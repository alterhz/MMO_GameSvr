
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
		if (m_listCommand.size() > 0)
		{
			ICommand *pCommand = m_listCommand.front();
			m_listCommand.pop_front();

			return pCommand;
		}

		return NULL;
	}

private:
	std::list<ICommand *> m_listCommand;
};

#endif