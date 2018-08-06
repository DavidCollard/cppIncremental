#ifndef MAIN
#define MAIN

#include "AbstractCommand.h"

int main();
//void test(exec_status*);

void test(exec_status*, exec_status*, std::mutex*, std::condition_variable*);
#endif
