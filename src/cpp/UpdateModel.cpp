#include <iostream>

#include "UpdateModel.h"

void updateModel(Model* model)
{
	tickNodes(model);
}

void tickNodes(Model* model)
{
	auto nodes = model->getNodes();

	std::cout << "#########################" << std::endl;

	for (auto it = nodes->begin(); it != nodes->end(); it++)
	{
		tickNode(it->second);
	}
}

void tickNode(Node* node)
{
	node->gainToMag();
	node->printStatus();
}

