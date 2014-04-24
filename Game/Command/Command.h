
#ifndef _COMMAND_
#define _COMMAND_

#include "ICommand.h"

class CommandEnterScene : public ICommand
{
public:
	virtual CommandType GetCommandType() { return CommandType_EnterScene; }

private:
	
};

#endif


