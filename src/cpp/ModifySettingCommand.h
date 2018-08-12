#ifndef MODIFYSETTINGCOMMAND
#define MODIFYSETTINGCOMMAND

#include <string>

#include "Model.h"
#include "AbstractCommand.h"

class ModifySettingCommand : public AbstractCommand
{
public:
	ModifySettingCommand(std::string, int);
	exec_status execute();

	std::string getStatus();
	std::string getError();

private:
	std::string _name;
	int _value;
};

#endif
