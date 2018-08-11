#include "Node.h"

#include <iostream>

Node::Node(int x, int y) : Node::Node(x, y, std::string())
{
}

Node::Node(int x, int y, std::string name) : Node::Node(x, y, name, 0, 0)
{
}

Node::Node(int x, int y, std::string name, float magnitude, float gain)
{
	_x = x;
	_y = y;
	_name = name;
	_magnitude = magnitude;
	_gain = gain;
}

int Node::getY()
{
	return _y;
}

int Node::getX()
{
	return _x;
}

std::string Node::getName()
{
	return _name;
}

float Node::getMagnitude()
{
	return _magnitude;
}

float Node::getGain()
{
	return _gain;
}

void Node::gainToMag()
{
	_magnitude += _gain;
}

void Node::printStatus()
{
	std::cout << _name << " @" << _x << ":" << _y << " |" << _magnitude << "| += " << _gain << std::endl;
}

