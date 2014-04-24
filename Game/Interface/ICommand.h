#ifndef _ICOMMAND_
#define _ICOMMAND_

enum CommandType
{
	CommandType_Null = 0,
	CommandType_Test,
	CommandType_EnterScene,	//½øÈë³¡¾°
};

class ICommand
{
public:
	virtual CommandType GetCommandType() { return CommandType_Null; }

private:

};

#endif