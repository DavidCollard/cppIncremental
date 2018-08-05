#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand() : AbstractCommand(0, 0)
{

}

HelpCommand::HelpCommand(int x, int y) : AbstractCommand(x, y)
{

}

void HelpCommand::printStatus()
{
	std::cout << "HelpCommand printStatus" << std::endl;
}
