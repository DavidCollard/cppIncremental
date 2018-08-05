#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "main.h"
#include "ProcessInput.h"

int main()
{
	std::string input;
	bool quit = false;
	exec_status status;
	while (!quit)
	{
		std::getline(std::cin, input);
		AbstractCommand* cmd = processInput(input);
		//cmd->printStatus();
		status = cmd->execute();
		if (status == EXEC_QUIT)
		{
			quit = true;
		}
		else if (status == EXEC_WARN)
		{
			cmd->warning();
		}
		else if (status == EXEC_ERR)
		{
			cmd->error();
		}
	}

	return 0;
}

