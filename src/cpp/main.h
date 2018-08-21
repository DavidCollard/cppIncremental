#ifndef MAIN
#define MAIN

#include "AbstractCommand.h"
#include "Model.h"
#include "NCursesWindow.h"

int main();

void test(Model*, NCursesWindow*, exec_status*, exec_status*, std::mutex*, std::condition_variable*);

#endif
