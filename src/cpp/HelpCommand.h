#ifndef HELPCOMMAND
#define HELPCOMMAND

#include "Model.h"
#include "AbstractCommand.h"

class HelpCommand : public AbstractCommand
{
public:
	HelpCommand();
	void printStatus();
	exec_status execute();
private:
	
};

#endif
