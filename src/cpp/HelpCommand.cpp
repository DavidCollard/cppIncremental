#include "HelpCommand.h"

HelpCommand::HelpCommand() : AbstractCommand()
{

}

std::string HelpCommand::getStatus()
{
	return "This is the help dialog\n"
		"h for help\n"
		"i <name> to insert a node\n"
		"e to expand the maximum number of nodes you can have\n"
		"u <name> [amount=1] to upgrade a node [amount] times\n"
		"s <setting>=<value> to change a setting\n"
		"q to quit";
}

exec_status HelpCommand::execute()
{
	return EXEC_CONT;
}

