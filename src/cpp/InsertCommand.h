#ifndef INSERTCOMMAND
#define INSERTCOMMAND

#include <string>

#include "Model.h"
#include "AbstractCommand.h"

class InsertCommand : public AbstractCommand
{
public:
	InsertCommand();
	InsertCommand(std::string);
	exec_status execute();
	
	std::string getStatus();

private:
	std::string _code;
};

#endif
