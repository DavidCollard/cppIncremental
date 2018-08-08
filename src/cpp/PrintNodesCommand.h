#ifndef PRINTNODESCOMMAND
#define PRINTNODESCOMMAND

#include "Model.h"
#include "AbstractCommand.h"

class PrintNodesCommand : public AbstractCommand
{
public:
	PrintNodesCommand();
	void printStatus();
	exec_status execute();
private:
	
};

#endif
