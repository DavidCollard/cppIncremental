#ifndef INSERTCOMMAND
#define INSERTCOMMAND

#include <string>

#include "AbstractCommand.h"

class InsertCommand : public AbstractCommand
{
public:
	InsertCommand();
	InsertCommand(std::string);
	exec_status execute();
	
	std::string getStatus();
	std::string getError();

private:
	std::string _code;
};

#endif
