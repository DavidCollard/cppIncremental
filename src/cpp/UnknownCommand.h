#ifndef UNKNOWNCOMMAND
#define UNKNOWNCOMMAND

#include "AbstractCommand.h"

class UnknownCommand : public AbstractCommand
{
public:
	UnknownCommand();
	void printStatus();
	exec_status execute();
	void warning();
	void error();
private:
	
};

#endif
