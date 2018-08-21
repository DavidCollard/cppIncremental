#ifndef EXPANDCOMMAND
#define EXPANDCOMMAND

#include <string>

#include "AbstractCommand.h"

class ExpandCommand : public AbstractCommand
{
public:
	ExpandCommand();
	exec_status execute();
	
	std::string getStatus();
	std::string getError();

private:

};

#endif
