#ifndef UPGRADENODECOMMAND
#define UPGRADENODECOMMAND

#include "Model.h"
#include "AbstractCommand.h"

class UpgradeNodeCommand : public AbstractCommand
{
public:
	UpgradeNodeCommand(std::string, int);
	exec_status execute();
	
	std::string getStatus();
	std::string getWarning();
	std::string getError();

private:
	std::string _code;
	int _amount;
};

#endif
