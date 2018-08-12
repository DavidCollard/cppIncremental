#include <iostream>

#include "UpdateModel.h"

void updateModel(Model* model, NCursesWindow* window)
{
	tickNodes(model, window);
}

void tickNodes(Model* model, NCursesWindow* window)
{
	auto nodes = model->getNodes();

	window->clearNodes();

	for (auto it = nodes->begin(); it != nodes->end(); it++)
	{
		tickNode(it->second);
		window->printNodes(it->second->getStatus());
	}

	window->refreshAll();
}

void tickNode(Node* node)
{
	node->gainToMag();
}

