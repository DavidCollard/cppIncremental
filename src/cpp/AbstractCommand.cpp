#include <iostream>
#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

std::string AbstractCommand::getStatus()
{
	return getNoImplStr("getStatus");
}

exec_status AbstractCommand::execute()
{
	return EXEC_NIMP;
}

exec_status AbstractCommand::execute(Model* model)
{
	_model = model;
	return this->execute();
}

std::string AbstractCommand::getWarning()
{
	return getNoImplStr("warning");
}

std::string AbstractCommand::getError()
{
	return getNoImplStr("error");
}

std::string AbstractCommand::getNoImplStr(std::string fName)
{
	return std::string("Virtual function '" + fName + "' not implemented");
}
