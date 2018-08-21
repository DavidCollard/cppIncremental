#include "ExpandCommand.h"

ExpandCommand::ExpandCommand() : AbstractCommand()
{

}

std::string ExpandCommand::getStatus()
{
	return "Expanded sucessfully";
}

std::string ExpandCommand::getError()
{
	return "Could not afford expansion";
}

exec_status ExpandCommand::execute()
{
	return _model->buyExpansion() ? EXEC_CONT : EXEC_ERR;
}
