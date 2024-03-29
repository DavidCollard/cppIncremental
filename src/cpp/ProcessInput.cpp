#include <string>
#include <regex>

#include "ProcessInput.h"
#include "AbstractCommand.h"
#include "ExpandCommand.h"
#include "HelpCommand.h"
#include "InsertCommand.h"
#include "ModifySettingCommand.h"
#include "QuitCommand.h"
#include "UnknownCommand.h"
#include "UpgradeNodeCommand.h"

const std::string reg_float = "([+-]?(?:(?:\\d+(?:\\.\\d*)?)|(?:\\.\\d+)))";
const std::string reg_int = "([+-]?[0-9]+)";
const std::string reg_str = "([^\\s]+)";

AbstractCommand* processInput(std::string input)
{
	AbstractCommand* cmd;
	std::smatch base_match;	

	const std::regex help_regex(" *[Hh] *");
	const std::regex quit_regex(" *[Qq] *");
	const std::regex insert_regex(" *[Ii] *" + reg_str + " *");
	const std::regex setting_regex(" *[Ss] * " + reg_str + "=" + reg_int + " *");
	const std::regex upgrade_regex(" *[Uu] * " + reg_str + " *" + reg_int + "? *");
	const std::regex expand_regex(" *[Ee] *"); 

	if (std::regex_match(input, base_match, help_regex))
	{
		cmd = new HelpCommand();
	}
	else if (std::regex_match(input, base_match, quit_regex))
	{
		cmd = new QuitCommand();
	}
	else if (std::regex_match(input, base_match, insert_regex))
	{
		std::string code = base_match[1];
		cmd = new InsertCommand(code);
	}
	else if (std::regex_match(input, base_match, setting_regex))
	{
		std::string name = base_match[1];
		int value = stoi(base_match[2]);
		cmd = new ModifySettingCommand(name, value);
	}
	else if (std::regex_match(input, base_match, upgrade_regex))
	{
		std::string code = base_match[1];
		int num = base_match[2].str().empty() ? 1 : stoi(base_match[2]);
		cmd = new UpgradeNodeCommand(code, num);
	}
	else if (std::regex_match(input, base_match, expand_regex))
	{
		cmd = new ExpandCommand();
	}
	else
	{
		cmd = new UnknownCommand();
	}
	return cmd;
}

