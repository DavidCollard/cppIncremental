#include <iostream>
#include "PrintNodesCommand.h"

PrintNodesCommand::PrintNodesCommand() : AbstractCommand()
{

}

void PrintNodesCommand::printStatus()
{
	std::cout << "PrintNodesCommand printStatus" << std::endl;
}

exec_status PrintNodesCommand::execute()
{
	auto nodes = _model->getNodes();
	
	for (auto it = nodes->begin(); it != nodes->end(); ++it)
	{
		it->second->printStatus();
	}

	return EXEC_CONT;
}

