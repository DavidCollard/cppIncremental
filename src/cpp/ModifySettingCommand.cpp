#include <iostream>
#include "ModifySettingCommand.h"

ModifySettingCommand::ModifySettingCommand(std::string name, int value) : AbstractCommand()
{
	_name = name;
	_value = value;
}

std::string ModifySettingCommand::getStatus()
{
	return "Sucessfully set '" + _name + "' to " + std::to_string(_value);
}

std::string ModifySettingCommand::getError()
{
	return _name + " is not a valid option";
}

exec_status ModifySettingCommand::execute()
{
	if (_name.compare("msec") == 0)
	{
		_model->getSettings()->setMsecPerTick(_value);
	}
	else
	{
		std::cout << _name << " is not a valid command" << std::endl;
		return EXEC_ERR;
	}

	return EXEC_CONT;
}

