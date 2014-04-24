
#ifndef _COMMANDMANAGER_
#define _COMMANDMANAGER_

#include <list>
#include "Command.h"

class CommandManager
{
public:
	// Í¶µÝÊÂ¼þ
	bool QueueCommand(ICommand *pCommand)
	{
		m_listCommand.push_back(pCommand);

		return true;
	}
	ICommand * PopCommand()
	{
		ICommand *pCommand = m_listCommand.front();
		m_listCommand.pop_front();

		return pCommand;
	}

private:
	std::list<ICommand *> m_listCommand;
};

#endif