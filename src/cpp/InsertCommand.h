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
	void printStatus();
	exec_status execute();
private:
	std::string _code;
};

#endif
