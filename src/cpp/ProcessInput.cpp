#include <stdlib.h>
#include <iostream>
#include <string>
#include <regex>

#include "ProcessInput.h"
#include "AbstractCommand.h"
#include "HelpCommand.h"
#include "QuitCommand.h"
#include "UnknownCommand.h"

const std::string reg_float = "([+-]?(?:(?:\\d+(?:\\.\\d*)?)|(?:\\.\\d+)))";
const std::string reg_int = "([+-]?[0-9]+)";

AbstractCommand* processInput(std::string input)
{
	AbstractCommand* cmd;
	std::smatch base_match;	

	const std::regex help_regex(" *[Hh] *");
	const std::regex quit_regex(" *[Qq] *");
	const std::regex int_test(reg_int);
	const std::regex float_test(reg_float);

	if (std::regex_match(input, base_match, help_regex))
	{
		cmd = new HelpCommand();
	}
	else if (std::regex_match(input, base_match, quit_regex))
	{
		cmd = new QuitCommand();
	}
	/*
	else if (std::regex_match(input, base_match, int_test))
	{
		std::cout << "int input" << std::endl;
		cmd = new UnknownCommand();
	}
	else if (std::regex_match(input, base_match, float_test))
	{
		std::cout << "float input" << std::endl;
		cmd = new UnknownCommand();
	}
	*/
	else
	{
		cmd = new UnknownCommand();
	}
	return cmd;
}

