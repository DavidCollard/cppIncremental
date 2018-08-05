#include <iostream>
#include "UnknownCommand.h"

UnknownCommand::UnknownCommand() : AbstractCommand()
{

}

void UnknownCommand::printStatus()
{
	std::cout << "UnknownCommand printStatus" << std::endl;
}

exec_status UnknownCommand::execute ()
{
	return EXEC_ERR;
}

void UnknownCommand::warning()
{
	std::cout << "Provided command did not match any known commands. Use <H> for help" << std::endl;
}

void UnknownCommand::error()
{
	std::cout << "Provided command did not match any known commands. Use <H> for help" << std::endl;
}

