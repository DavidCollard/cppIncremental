#include <stdlib.h>
#include <iostream>
#include <string>
#include <regex>

#include "ProcessInput.h"
#include "AbstractCommand.h"
#include "HelpCommand.h"
#include "QuitCommand.h"
#include "UnknownCommand.h"

AbstractCommand* processInput(std::string input)
{
	AbstractCommand* cmd;
	std::smatch base_match;	

	const std::regex help_regex(" *[Hh] *");
	const std::regex quit_regex(" *[Qq] *");
	if (std::regex_match(input, base_match, help_regex))
	{
		cmd = new HelpCommand();
	}
	else if (std::regex_match(input, base_match, quit_regex))
	{
		cmd = new QuitCommand();
	}
	else
	{
		cmd = new UnknownCommand();
	}
	return cmd;
}

