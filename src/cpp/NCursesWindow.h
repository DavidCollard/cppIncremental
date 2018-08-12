#ifndef NCURSESWINDOW
#define NCURSESWINDOW

#include <ncurses.h>
#include <string>

#include "exec_status.h"

class NCursesWindow
{
public:
	NCursesWindow();
	~NCursesWindow();
	void resize();
	void refreshAll();
	std::string getString(); // user input string

	void clearNodes();
	void clearLog();
	void clearCmd();

	void printLog(std::string);	
	void printLog(std::string, exec_status);
	void printNodes(std::string);

	//static void* resizeHandler();

private:
	WINDOW* _nodes;
	WINDOW* _log;
	WINDOW* _cmd;
};
	

#endif
