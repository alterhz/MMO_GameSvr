#ifndef _ISCENE_
#define _ISCENE_

#include "CommandManager.h"

class IScene : public CommandManager
{
public:
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int GetIndex() const { return m_nIndex; }

public:
	// ĞÄÌøÖ´ĞĞ
	virtual bool DoTick(unsigned long nElapsed) = 0;

private:
	int m_nIndex;

};


#endif
