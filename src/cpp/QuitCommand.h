#ifndef QUITCOMMAND
#define QUITCOMMAND

#include "AbstractCommand.h"

class QuitCommand : public AbstractCommand
{
public:
	QuitCommand();
	void printStatus();
	exec_status execute();
private:
	
};

#endif
