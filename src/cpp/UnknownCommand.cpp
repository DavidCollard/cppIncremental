#include <iostream>
#include "UnknownCommand.h"

UnknownCommand::UnknownCommand() : AbstractCommand()
{

}

std::string UnknownCommand::getStatus()
{
	return "UnknownCommand printStatus";
}

exec_status UnknownCommand::execute ()
{
	return EXEC_ERR;
}

std::string UnknownCommand::getWarning()
{
	return "W: Provided command did not match any known commands. Use <H> for help";
}

std::string UnknownCommand::getError()
{
	return "E: Provided command did not match any known commands. Use <H> for help";
}

