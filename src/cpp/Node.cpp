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
	return getUpgradeCost(1);
}

float Node::getUpgradeCost(int amount)
{
	// (1 << amount) - 1 = |amount| 1's
	// represents |amount| levels of cost in the next line
	int shift_amt = (1 << amount) - 1;

	// cheap exponent - scales the amount of levels for the purchase
	return static_cast<float>(shift_amt << _level);
}

void Node::upgrade(int amount)
{
	_level += amount;
}

int Node::getLevel()
{
	return _level;
}

