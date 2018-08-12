#include <iostream>
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

exec_status InsertCommand::execute()
{
	Node* node = new Node(0, 0, _code);
	_model->addNode(_code, node);

	return EXEC_CONT;
}
