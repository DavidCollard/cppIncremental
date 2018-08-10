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

Node* Model::getNode(std::string key)
{
	return _nodes[key];
}

void Model::addNode(std::string key, Node* node)
{
	_nodes[key] = node;
	//_nodes.insert(key, node);
}

bool Model::removeNode(std::string key)
{
	if (_nodes.find(key) == _nodes.end())
		return false;
	_nodes.erase(key);
	return true;
}

const std::unordered_map<std::string, Node*>* Model::getNodes()
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

