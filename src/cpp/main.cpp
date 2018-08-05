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
	while (!quit)
	{
		std::cin >> input;
		AbstractCommand* cmd = processInput(input);
		cmd->printStatus();
		if (input[0] == 'a')
			quit = true;
	}

	return 0;
}

