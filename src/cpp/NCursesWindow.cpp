#include "NCursesWindow.h"
#include <signal.h>

NCursesWindow::NCursesWindow()
{
	initscr();
	//resizeHandler();
	//resize();
	
	//signal(SIGWINCH, resizeHandler);
	
	int nh, nw, hw;
	getmaxyx(stdscr, nh, nw);
	
	hw = nw/2; // half-width

	_nodes = newwin(nh-1, nw - hw, 0, 0); // top left
	_log = newwin(nh-1, hw, 0, hw); // top right
	_cmd = newwin(1, nw, nh-1, 0); // bottom row

	scrollok(_log, TRUE);
	scrollok(_cmd, TRUE);
	cbreak();
	noecho();

	if (has_colors() == TRUE)
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	}
}

NCursesWindow::~NCursesWindow()
{
	endwin();
}

void NCursesWindow::resize()
{
	int nh, nw, hw;
	getmaxyx(stdscr, nh, nw);
	hw = nw/2; // half-width

	wresize(_nodes, nh - 1, nw - hw);
	wresize(_log, nh - 1, hw);
	wresize(_cmd, 1, nw);

	refreshAll();
}

void NCursesWindow::refreshAll()
{
	wrefresh(_log);
	wrefresh(_cmd);
	wrefresh(_nodes);
}

std::string NCursesWindow::getString()
{
	std::string input;
	int ch = getch();

	while (ch != '\n')
	{
		input.push_back(ch);
		waddch(_cmd,ch);
		wrefresh(_cmd);
		ch = getch();	
	}

	clearCmd();
	printLog("> " + input);

	return input;
}

void NCursesWindow::clearNodes()
{
	werase(_nodes);
	wmove(_nodes, 0, 0);
}

void NCursesWindow::clearLog()
{
	werase(_log);
	wmove(_log, 0, 0);
}

void NCursesWindow::clearCmd()
{
	werase(_cmd);
	wmove(_cmd, 0, 0);
}

void NCursesWindow::printLog(std::string output)
{
	wprintw(_log, (output + "\n").c_str());
}

void NCursesWindow::printLog(std::string output, exec_status status)
{
	if (has_colors() == TRUE)
	{
		if(status == EXEC_ERR)
		{
			// print red
			wattron(_log, COLOR_PAIR(1));
			printLog(output);
			wattroff(_log, COLOR_PAIR(1));
		}
		else if(status == EXEC_WARN)
		{
			// print yellow
			wattron(_log, COLOR_PAIR(2));
			printLog(output);
			wattroff(_log, COLOR_PAIR(2));
		}
		else
		{
			printLog(output);
		}
	}
	else
	{
		printLog(output);
	}
}

void NCursesWindow::printNodes(std::string node)
{
	wprintw(_nodes, (node + "\n").c_str());
}



/*
static void* NCursesWindow::resizeHandler()
{
	int nh, nw;
	getmaxyx(stdscr, nh, nw);
	wresize(_screen, nh, nw);
	wrefresh(_screen);
	return (void*)(&(nh + nw));
}
*/
