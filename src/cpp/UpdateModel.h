#ifndef UPDATEMODEL
#define UPDATEMODEL

#include "Model.h"
#include "NCursesWindow.h"

void updateModel(Model *, NCursesWindow *);

void tickNodes(Model *, NCursesWindow *);

void tickNode(Node *);

#endif
