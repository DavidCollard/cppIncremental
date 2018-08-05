#ifndef HELPCOMMAND
#define HELPCOMMAND

#include "AbstractCommand.h"

class HelpCommand : public AbstractCommand
{
public:
	HelpCommand();
	HelpCommand(int, int);
	void printStatus();
private:
	
};

#endif
