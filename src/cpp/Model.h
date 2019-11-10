#ifndef MODEL
#define MODEL

#include <string>
#include <map>

#include "Node.h"
#include "Settings.h"

class Model{
public:
	Model();
	Model(std::string);
	~Model();
	
	Node* getNode(std::string);
	
	void addNode(std::string, Node*);
	bool hasNode(std::string);
	bool removeNode(std::string);
	std::map<std::string, Node*>* getNodes();
	
	std::string getName();

	Settings* getSettings();

	unsigned int getMaxNodes();
	void incMaxNodes();

	void addCurrency(float);
	void subCurrency(float);
	float getCurrency();

	float getExpandCost();
	bool buyExpansion();

private:
	std::map<std::string, Node*> _nodes;
	std::string _name;
	Settings* _settings;

	unsigned int _max_nodes;
	float _currency;
};

#endif
