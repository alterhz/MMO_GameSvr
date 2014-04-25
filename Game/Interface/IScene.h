#ifndef _ISCENE_
#define _ISCENE_

#include "CommandManager.h"

class IScene : public CommandManager
{
public:
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int GetIndex() const { return m_nIndex; }

public:
	// ����ִ��
	virtual bool DoTick(unsigned long nElapsed)
	{
		ICommand *pCommand = PopCommand();

		return OnRunCommand(pCommand);;
	}
	// ִ��Command�¼�
	virtual bool OnRunCommand(ICommand *pCommand) = 0;

private:
	int m_nIndex;

};


#endif
