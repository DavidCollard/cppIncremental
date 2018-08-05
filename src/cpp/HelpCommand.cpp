#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand() : AbstractCommand()
{

}

void HelpCommand::printStatus()
{
	std::cout << "HelpCommand printStatus" << std::endl;
}

exec_status HelpCommand::execute ()
{
	std::cout << 	"This is the help dialog\n"
			"Press h for help\n"
			"Press q to quit" 
			<< std::endl;
	return EXEC_CONT;
}
