#ifndef EXEC_STATUS
#define EXEC_STATUS

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

#endif
