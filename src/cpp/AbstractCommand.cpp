#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

AbstractCommand::AbstractCommand(int x, int y)
{
	_x = x;
	_y = y;
}

int AbstractCommand::getY()
{
	return _y;
}

int AbstractCommand::getX()
{
	return _x;
}
