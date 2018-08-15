#ifndef UPGRADENODECOMMAND
#define UPGRADENODECOMMAND

#include <string>

#include "Model.h"
#include "AbstractCommand.h"

class UpgradeNodeCommand : public AbstractCommand
{
public:
	UpgradeNodeCommand(std::string);
	exec_status execute();
	
	std::string getStatus();
	std::string getWarning();
	std::string getError();

private:
	std::string _code;	
};

#endif
