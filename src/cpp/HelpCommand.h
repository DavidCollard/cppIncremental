#ifndef HELPCOMMAND
#define HELPCOMMAND

#include "AbstractCommand.h"

class HelpCommand : public AbstractCommand
{
public:
	HelpCommand();
	exec_status execute();
	
	std::string getStatus();

private:
	
};

#endif
