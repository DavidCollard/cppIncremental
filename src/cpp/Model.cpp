#include <unordered_map>

#include "Model.h"
#include "Node.h"


Model::Model()
{
	_name = "test name";
}

Model::Model(std::string name)
{
	_name = name;
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

std::string Model::getName()
{
	return _name;
}

//unordered_map<std::string, Node*> _nodes;


