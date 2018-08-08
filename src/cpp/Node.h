#ifndef NODE
#define NODE

#include <string>

class Node{
public:
	Node(int, int);
	Node(int, int, std::string);
	int getY();
	int getX();
	std::string getName();
	void printStatus();

private:
	int _x, _y;
	std::string _name;
};

#endif
