#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <chrono>

#include "main.h"
#include "ProcessInput.h"
#include "Model.h"

int main()
{
	// init game model
	Model* model = new Model();

	exec_status p_status = EXEC_CONT;
	exec_status t_status = EXEC_CONT;

	// spawn thread to automatically update game model
	std::mutex m;
	std::condition_variable cv;
	std::thread game_thread (test, &p_status, &t_status, &m, &cv);

	// input loop
	std::string input;
	bool quit = false;
	while (!quit)
	{
		std::getline(std::cin, input);
		AbstractCommand* cmd = processInput(input);

		// pause update thread for duration of execute method
		// once it completes it's current loop
		
		p_status = EXEC_WAIT; // self status to wait for lock
		t_status = EXEC_PAUSE; // thread status to pause on next cycle
		std::unique_lock<std::mutex> lk(m);
		
		while (p_status == EXEC_WAIT)
		{
			cv.wait(lk);
		}

		p_status = cmd->execute(model);

		t_status = EXEC_CONT;
		lk.unlock();
		cv.notify_one();

		// handle exec status
		if (p_status == EXEC_QUIT)
		{
			quit = true;
		}
		else if (p_status == EXEC_WARN)
		{
			cmd->warning();
		}
		else if (p_status == EXEC_ERR)
		{
			cmd->error();
		}
	}

	// stop thread
	game_thread.join();

	// clean up/save model
	// TODO

	return 0;
}

#define MSEC_PER_TICK 200

void test(exec_status* p_status, exec_status* t_status, std::mutex* m, std::condition_variable* cv)
{
	std::unique_lock<std::mutex> lk(*m);
		
	const int ticks_per_report = 10;
	int curr_ticks = 0;

	while(*p_status != EXEC_QUIT)
	{
		//sleep(3);

		std::this_thread::sleep_for(std::chrono::milliseconds(MSEC_PER_TICK));

		curr_ticks = (curr_ticks + 1)%ticks_per_report;
		
		if (curr_ticks == 0)
		{
			//std::cout << "lol" << std::endl;
		}

		if (*t_status == EXEC_PAUSE){
			cv->notify_one();
			*p_status = EXEC_CONT;
			while (*t_status == EXEC_PAUSE)
			{
				cv->wait(lk);
			}
		}
	}
	lk.unlock(); // for safety :)
}

