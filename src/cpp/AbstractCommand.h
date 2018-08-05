#ifndef ABSTRACTCOMMAND
#define ABSTRACTCOMMAND

enum exec_status
{
	EXEC_CONT, // continue
	EXEC_QUIT, // quit
	EXEC_ERR,  // error
	EXEC_WARN, // warning
};

class AbstractCommand
{
public:
	AbstractCommand();

	virtual void printStatus();
	virtual exec_status execute();
	virtual void warning();
	virtual void error();

private:
	void printNoImpl(std::string fName);

};



#endif
