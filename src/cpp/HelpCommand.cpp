#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand() : AbstractCommand()
{

}

std::string HelpCommand::getStatus()
{
	return "This is the help dialog\n"
		"h for help\n"
		"i <name> to insert a node\n"
		"p to print all nodes\n"
		"s <setting>=<value> to change a setting\n"
		"q to quit";
}

exec_status HelpCommand::execute()
{
	return EXEC_CONT;
}

