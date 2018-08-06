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
	return EXEC_NIMP;
}

exec_status AbstractCommand::execute(Model* model)
{
	_model = model;
	return this->execute();
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
