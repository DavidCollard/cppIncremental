#include <iostream>

#include "UpdateModel.h"

void updateModel(Model* model, NCursesWindow* window)
{
	tickNodes(model);
	refreshWindow(model, window);
}

void tickNodes(Model* model)
{
	auto nodes = model->getNodes();

	for (auto it = nodes->begin(); it != nodes->end(); it++)
	{
		tickNode(it->second);
	}
}

void tickNode(Node* node)
{
	node->gainToMag();
}

void refreshWindow(Model* model, NCursesWindow* window)
{
	// nodes
	auto nodes = model->getNodes();
	window->clearNodes();
	
	for (auto it = nodes->begin(); it != nodes->end(); it++)
	{
		window->printNodes(it->second);
	}

	// status
	window->clearStatus();
	window->printStatus(model);

	window->refreshAll();
}

