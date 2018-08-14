#ifndef UPDATEMODEL
#define UPDATEMODEL

#include "Model.h"
#include "NCursesWindow.h"

void updateModel(Model *, NCursesWindow *);

void tickNodes(Model *);
void tickNode(Node *);

void refreshWindow(Model*, NCursesWindow*);

#endif
