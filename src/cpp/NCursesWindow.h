#ifndef NCURSESWINDOW
#define NCURSESWINDOW

#include <ncurses.h>
#include <string>

#include "Model.h"
#include "Node.h"
#include "exec_status.h"

class NCursesWindow
{
public:
	NCursesWindow();
	~NCursesWindow();
	
	void initialize();
	void deinitialize();

	void resize();
	void clearAll();
	void refreshAll();
	std::string getString(); // user input string

	void clearNodes();
	void clearLog();
	void clearCmd();
	void clearStatus();

	void printLog(std::string);	
	void printLog(std::string, exec_status);
	void printNodes(Node *);
	void printStatus(Model *);

	static void resizeHandler(int);
	static NCursesWindow* getInstance();

private:
	WINDOW* _nodes;
	WINDOW* _log;
	WINDOW* _cmd;
	WINDOW* _status;

	static NCursesWindow* _instance;
};
	

#endif
