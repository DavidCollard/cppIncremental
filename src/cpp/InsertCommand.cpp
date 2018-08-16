#include "InsertCommand.h"

InsertCommand::InsertCommand() : AbstractCommand()
{

}

InsertCommand::InsertCommand(std::string code) : AbstractCommand()
{
	_code = code;
}

std::string InsertCommand::getStatus()
{
	return "Inserted node " + _code;
}

std::string InsertCommand::getError()
{
	return "Could not insert node " + _code;
}

exec_status InsertCommand::execute()
{
	Node* node = new Node(_code);
	if (_model->hasNode(_code) || _model->getNodes()->size() >= _model->getMaxNodes())
	{
		return EXEC_ERR;
	}
	_model->addNode(_code, node);

	return EXEC_CONT;
}
