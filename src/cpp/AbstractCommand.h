#ifndef ABSTRACTCOMMAND
#define ABSTRACTCOMMAND

class AbstractCommand
{
public:
	AbstractCommand();
	AbstractCommand(int, int);
	int getX();
	int getY();

private:
	int _x, _y;
};

#endif
