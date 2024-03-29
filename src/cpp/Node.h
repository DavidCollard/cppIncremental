#ifndef NODE
#define NODE

#include <string>

class Node {
public:
	Node();
	Node(std::string);
	Node(std::string, float);
	std::string getName();
	float getGain();

	std::string getStatus();

	float getUpgradeCost();
	float getUpgradeCost(int);
	void upgrade(int);
	int getLevel();

private:
	std::string _name;
	float _gain;
	int _level;
};

#endif
