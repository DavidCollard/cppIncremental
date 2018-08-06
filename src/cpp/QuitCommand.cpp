#include <iostream>
#include "QuitCommand.h"

QuitCommand::QuitCommand() : AbstractCommand()
{

}

void QuitCommand::printStatus()
{
	std::cout << "QuitCommand printStatus" << std::endl;
}

exec_status QuitCommand::execute()
{
	return EXEC_QUIT;
}

