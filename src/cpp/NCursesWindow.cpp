#include "NCursesWindow.h"
#include <signal.h>

NCursesWindow* NCursesWindow::_instance = new NCursesWindow();

NCursesWindow::NCursesWindow()
{
	initialize();
	
	signal(SIGWINCH, resizeHandler);
}

NCursesWindow::~NCursesWindow()
{
	deinitialize();
}

void NCursesWindow::initialize()
{
	initscr();

	// windows and sizing
	int nh, nw, hw;
	getmaxyx(stdscr, nh, nw);
	
	hw = nw/2; // half-width

	_nodes = newwin(nh-2, nw - hw, 0, 0); // top left
	_log = newwin(nh-2, hw, 0, hw); // top right
	_status = newwin(1, nw, nh-2, 0); // 1 above bottom
	_cmd = newwin(1, nw, nh-1, 0); // bottom row
	
	/* DEBUG INFO
	printLog(std::to_string(nh) + "H:" + std::to_string(nw) + "W");
	printLog(std::to_string(nh-2) + ":" + std::to_string(nw-hw));
	printLog(std::to_string(nh-2) + ":" + std::to_string(hw));
	printLog(std::to_string(1) + ":" + std::to_string(nw));
	printLog(std::to_string(1) + ":" + std::to_string(nw));
	*/
	
	// settings
	scrollok(_log, TRUE);
	cbreak();
	noecho();

	if (has_colors() == TRUE)
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK); // error
		init_pair(2, COLOR_YELLOW, COLOR_BLACK); // warning
	}

	keypad(stdscr, TRUE);
	curs_set(0);
}

void NCursesWindow::deinitialize()
{
	endwin();
}

void NCursesWindow::resize()
{
	// not perfect, but better than nothing :/
	deinitialize();
	initialize();
	clearAll();
	refreshAll();
}

void NCursesWindow::clearAll()
{
	clearLog();
	clearCmd();
	clearNodes();
	clearStatus();
}

void NCursesWindow::refreshAll()
{
	wrefresh(_log);
	wrefresh(_cmd);
	wrefresh(_nodes);
	wrefresh(_status);
}

std::string NCursesWindow::getString()
{
	std::string input;
	int ch = getch();

	while (ch != '\n')
	{
		if (ch == KEY_BACKSPACE)
		{
			if (input.size() > 0)
			{
				input.pop_back();	
			}
		}
		else if (ch == KEY_RESIZE)
		{
			//clear();
		}
		else
		{
			input.push_back(ch);
		}
		werase(_cmd);
		mvwprintw(_cmd, 0, 0, input.c_str());
		wrefresh(_cmd);
		ch = getch();
	}

	clearCmd();
	printLog("> " + input);
	refreshAll();
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

void NCursesWindow::clearStatus()
{
	werase(_status);
	wmove(_status, 0, 0);
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

void NCursesWindow::printNodes(Node* node)
{
	wprintw(_nodes, (node->getName() + "\t").c_str());
	wprintw(_nodes, ("+" + std::to_string(node->getGain()) + "\t").c_str());
	wprintw(_nodes, ("L" + std::to_string(node->getLevel()) + "\t").c_str());
	wprintw(_nodes, ("C" + std::to_string(node->getUpgradeCost()) + "\t").c_str());
	wprintw(_nodes, "\n");
}

void NCursesWindow::printStatus(Model* model)
{
	wprintw(_status, (std::to_string(model->getCurrency()) + "\t").c_str());
	
	if (has_colors() == TRUE)
	{
		if (model->getNodes()->size() < model->getMaxNodes())
		{
			wattron(_status, COLOR_PAIR(2));
		}
		else
		{
			wattron(_status, COLOR_PAIR(1));
		}
	}
	
	wprintw(_status, (std::to_string(model->getNodes()->size()) + "/" + std::to_string(model->getMaxNodes()) + "\t").c_str());
	
	if (has_colors() == TRUE)
	{
		if (model->getNodes()->size() < model->getMaxNodes())
		{
			wattroff(_status, COLOR_PAIR(2));
		}
		else
		{
			wattroff(_status, COLOR_PAIR(1));
		}
	}
}

NCursesWindow* NCursesWindow::getInstance()
{
	return _instance;
}

void NCursesWindow::resizeHandler(int signum)
{
	signum++;
	getInstance()->resize();
}

