#ifndef MAIN
#define MAIN

#include "AbstractCommand.h"
#include "Settings.h"

int main();
//void test(exec_status*);

void test(Settings*, exec_status*, exec_status*, std::mutex*, std::condition_variable*);
#endif
