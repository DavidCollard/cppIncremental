#ifndef NODE
#define NODE

#include <string>

class Node{
public:
	Node(int, int);
	Node(int, int, std::string);
	Node(int, int, std::string, float, float);
	int getY();
	int getX();
	std::string getName();
	float getMagnitude();
	float getGain();

	void gainToMag();

	void printStatus();
	std::string getStatus();

private:
	int _x, _y;
	std::string _name;
	float _magnitude;
	float _gain;
};

#endif
