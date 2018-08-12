#include <unordered_map>

#include "Model.h"
#include "Node.h"


Model::Model() : Model("default name")
{
}

Model::Model(std::string name)
{
	_name = name;
	_settings = new Settings();
}

Model::~Model()
{
	delete _settings;
}

Node* Model::getNode(std::string key)
{
	return _nodes[key];
}

void Model::addNode(std::string key, Node* node)
{
	_nodes[key] = node;
}

bool Model::hasNode(std::string key)
{
	return _nodes.find(key) != _nodes.end();
}

bool Model::removeNode(std::string key)
{
	if (!hasNode(key))
		return false;
	_nodes.erase(key);
	return true;
}

std::unordered_map<std::string, Node*>* Model::getNodes()
{
	return &_nodes;
}

std::string Model::getName()
{
	return _name;
}

Settings* Model::getSettings()
{
	return _settings;
}

