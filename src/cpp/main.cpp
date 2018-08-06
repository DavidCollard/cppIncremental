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

#include "main.h"
#include "ProcessInput.h"

int main()
{
	// init game model
	// TODO
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

		p_status = cmd->execute();
		
		t_status = EXEC_CONT;
		lk.unlock();
		cv.notify_one();

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
	// TODO

	game_thread.join();

	// clean up/save model
	// TODO

	return 0;
}

void test(exec_status* p_status, exec_status* t_status, std::mutex* m, std::condition_variable* cv)
{
	std::unique_lock<std::mutex> lk(*m);
	
	while(*p_status != EXEC_QUIT)
	{
		sleep(3);
		std::cout << "lol" << std::endl;
	
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

