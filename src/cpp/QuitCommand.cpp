#include "QuitCommand.h"

QuitCommand::QuitCommand() : AbstractCommand()
{

}

std::string QuitCommand::getStatus()
{
	return "QuitCommand printStatus";
}

exec_status QuitCommand::execute()
{
	return EXEC_QUIT;
}

