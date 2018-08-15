#include "Node.h"

#include <iostream>

Node::Node() : Node::Node(std::string())
{
}

Node::Node(std::string name) : Node::Node(name, 0)
{
}

Node::Node(std::string name, float gain)
{
	_name = name;
	_gain = gain;
	_level = 1;
}

std::string Node::getName()
{
	return _name;
}

float Node::getGain()
{
	return _gain * _level;
}

std::string Node::getStatus()
{
	return std::string(_name + " +" + std::to_string(_gain));
}

float Node::getUpgradeCost()
{
	// cheap exponent
	return static_cast<float>(1 << _level);
}

void Node::upgrade()
{
	_level++;
}

int Node::getLevel()
{
	return _level;
}

