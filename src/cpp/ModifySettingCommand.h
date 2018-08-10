#ifndef MODIFYSETTINGCOMMAND
#define MODIFYSETTINGCOMMAND

#include <string>

#include "Model.h"
#include "AbstractCommand.h"

class ModifySettingCommand : public AbstractCommand
{
public:
	ModifySettingCommand(std::string, int);
	void printStatus();
	exec_status execute();
private:
	std::string _name;
	int _value;
};

#endif
