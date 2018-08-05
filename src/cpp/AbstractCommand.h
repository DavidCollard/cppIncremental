#ifndef ABSTRACTCOMMAND
#define ABSTRACTCOMMAND

class AbstractCommand
{
public:
	AbstractCommand();
	AbstractCommand(int, int);
	int getX();
	int getY();

	virtual void printStatus();

private:
	int _x, _y;
};

#endif
