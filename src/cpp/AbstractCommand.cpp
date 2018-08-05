#include <iostream>
#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

void AbstractCommand::printStatus()
{
	printNoImpl("printStatus");
}

exec_status AbstractCommand::execute()
{
	printNoImpl("execute");
	return EXEC_WARN;
}

void AbstractCommand::warning()
{
	printNoImpl("warning");
}

void AbstractCommand::error()
{
	printNoImpl("error");
}

void AbstractCommand::printNoImpl(std::string fName)
{
	std::cout << "Virtual function '" << fName << "' not implemented" << std::endl;
}
