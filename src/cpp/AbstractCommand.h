#ifndef ABSTRACTCOMMAND
#define ABSTRACTCOMMAND

#include "Model.h"

enum exec_status
{
	EXEC_CONT, // continue
	EXEC_QUIT, // quit
	EXEC_ERR,  // error
	EXEC_WARN, // warning
	EXEC_PAUSE, // pause process
	EXEC_WAIT, // waiting
	EXEC_NIMP, // not implemented
};

class AbstractCommand
{
public:
	AbstractCommand();

	virtual void printStatus();
	virtual exec_status execute();
	virtual exec_status execute(Model*);
	virtual void warning();
	virtual void error();

private:
	void printNoImpl(std::string fName);

protected:
	Model* _model;
};



#endif
