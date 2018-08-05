#include <iostream>
#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

AbstractCommand::AbstractCommand(int x, int y)
{
	_x = x;
	_y = y;
}

void AbstractCommand::printStatus()
{
	std::cout << "Virual function printStatus not implemented" << std::endl;
}

int AbstractCommand::getY()
{
	return _y;
}

int AbstractCommand::getX()
{
	return _x;
}
