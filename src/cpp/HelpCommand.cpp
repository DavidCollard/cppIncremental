#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand() : AbstractCommand()
{

}

void HelpCommand::printStatus()
{
	std::cout << "HelpCommand printStatus" << std::endl;
}

exec_status HelpCommand::execute()
{
	std::cout << 	"This is the help dialog\n"
			"h for help\n"
			"i <name> to insert a node\n"
			"p to print all nodes\n"
			"s <setting>=<value> to change a setting\n"
			"q to quit"
			<< std::endl;
	return EXEC_CONT;
}

