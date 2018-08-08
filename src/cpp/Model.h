#ifndef MODEL
#define MODEL

#include <string>
#include <unordered_map>

#include "Node.h"

class Model{
public:
	Model();
	Model(std::string);
	Node* getNode(std::string);
	void addNode(std::string, Node*);
	bool removeNode(std::string);

	const std::unordered_map<std::string, Node*>* getNodes();

	std::string getName();

private:
	std::unordered_map<std::string, Node*> _nodes;
	std::string _name;
};

#endif
