#ifndef UNKNOWNCOMMAND
#define UNKNOWNCOMMAND

#include "AbstractCommand.h"

class UnknownCommand : public AbstractCommand
{
public:
	UnknownCommand();
	exec_status execute();
	
	std::string getStatus();
	std::string getWarning();
	std::string getError();
private:
	
};

#endif
