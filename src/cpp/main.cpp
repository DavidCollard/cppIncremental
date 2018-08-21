#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <chrono>

#include "main.h"
#include "ProcessInput.h"
#include "Model.h"
#include "Settings.h"
#include "UpdateModel.h"
#include "NCursesWindow.h"

int main()
{
	// init window
	NCursesWindow* window = NCursesWindow::getInstance();
	
	window->printLog("Welcome. Press h for help. You should probably start by inserting a node :)");

	// init game model
	Model* model = new Model();

	exec_status p_status = EXEC_CONT;
	exec_status t_status = EXEC_CONT;

	// spawn thread to automatically update game model
	std::mutex m;
	std::condition_variable cv;
	std::thread game_thread (test, model, window, &p_status, &t_status, &m, &cv);

	// input loop
	std::string input;
	bool quit = false;
	while (!quit)
	{
		input = window->getString();
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
		else if (p_status == EXEC_CONT)
		{
			window->printLog(cmd->getStatus(), p_status);
		}
		else if (p_status == EXEC_WARN)
		{
			window->printLog(cmd->getWarning(), p_status);
		}
		else if (p_status == EXEC_ERR)
		{
			window->printLog(cmd->getError(), p_status);
		}
	}

	// stop thread
	game_thread.join();

	// explicitly called
	delete window;

	return 0;
}

// thread method
void test(Model* model, NCursesWindow* window, exec_status* p_status, exec_status* t_status, std::mutex* m, std::condition_variable* cv)
{
	std::unique_lock<std::mutex> lk(*m);
	
	while(*p_status != EXEC_QUIT)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(model->getSettings()->getMsecPerTick()));

		updateModel(model, window);

		if (*t_status == EXEC_PAUSE)
		{
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

