#ifndef _ISCENE_
#define _ISCENE_

class IScene
{
public:
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int GetIndex() const { return m_nIndex; }

public:
	// 投递事件
	bool QueueCommand(ICommand *pCommand)
	{
		m_listCommand.push_back(pCommand);

		return true;
	}

public:
	// 心跳执行
	virtual bool DoTick(unsigned long nElapsed);

private:
	int m_nIndex;
	std::list<ICommand *> m_listCommand;

};


#endif
