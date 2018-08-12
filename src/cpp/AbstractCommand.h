#ifndef ABSTRACTCOMMAND
#define ABSTRACTCOMMAND

#include "Model.h"
#include "exec_status.h"

class AbstractCommand
{
public:
	AbstractCommand();

	//virtual void printStatus();
	virtual exec_status execute();
	exec_status execute(Model*);
	
	virtual std::string getStatus();
	virtual std::string getWarning();
	virtual std::string getError();

private:
	void printNoImpl(std::string fName);
	std::string getNoImplStr(std::string);

protected:
	Model* _model;
};



#endif
