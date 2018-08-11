#ifndef MAIN
#define MAIN

#include "AbstractCommand.h"
#include "Model.h"

int main();

void initModel(Model*);

void test(Model*, exec_status*, exec_status*, std::mutex*, std::condition_variable*);

#endif
