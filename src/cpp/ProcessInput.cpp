#include <stdlib.h>
#include <iostream>
#include <string>
#include "ProcessInput.h"
#include "AbstractCommand.h"
#include "HelpCommand.h"

AbstractCommand* processInput(std::string input)
{
	AbstractCommand* cmd;
	if (input[0] == 'h')
	{
		cmd = new HelpCommand();
	}
	else
	{
		cmd = new AbstractCommand(0, 0);
	}
	return cmd;
}

