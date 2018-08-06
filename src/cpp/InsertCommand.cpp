#include <iostream>
#include "InsertCommand.h"

InsertCommand::InsertCommand() : AbstractCommand()
{

}

InsertCommand::InsertCommand(std::string code) : AbstractCommand()
{
	_code = code;
}

void InsertCommand::printStatus()
{
	std::cout << "InsertCommand printStatus" << std::endl;
}

exec_status InsertCommand::execute()
{
	Node* node = new Node(0, 0);
	_model->addNode(_code, node);
	
	std::cout << "Inserted node " << _code << std::endl;

	return EXEC_CONT;
}
