#ifndef QUITCOMMAND
#define QUITCOMMAND

#include "AbstractCommand.h"

class QuitCommand : public AbstractCommand
{
public:
	QuitCommand();
	std::string getStatus();
	exec_status execute();
private:
	
};

#endif
