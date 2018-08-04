#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

#include "main.h"
//#include "AbstractCommand.h"

int main()
{
	std::cout << "hello world" << std::endl;

	AbstractCommand* cmd = processInput("test");
	std::cout << cmd->getX() << ":" << cmd->getY() << std::endl;

	return 0;
}

AbstractCommand* processInput(std::string input)
{
	AbstractCommand* cmd = new AbstractCommand(0, 0);
	std::cout << input << std::endl;
	return cmd;
}


