#include "Node.h"

#include <iostream>

Node::Node(int x, int y) : Node::Node(x, y, std::string())
{
}

Node::Node(int x, int y, std::string name)
{
	_x = x;
	_y = y;
	_name = name;
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

void Node::printStatus()
{
	std::cout << _name << " @" << _x << ":" << _y << std::endl;
}

