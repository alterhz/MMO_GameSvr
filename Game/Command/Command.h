
#ifndef _COMMAND_
#define _COMMAND_

#include "ICommand.h"


class CObj;
class CommandEnterScene : public ICommand
{
public:
	virtual CommandType GetCommandType() { return CommandType_EnterScene; }

	void SetSceneIndex(int nIndex) { m_nSceneIndex = nIndex; }
	int GetSceneIndex() const { return m_nSceneIndex; }
	void SetObj(CObj *pObj) { m_pObj = pObj; }
	CObj * GetObj() const { return m_pObj; }

private:
	int m_nSceneIndex;
	CObj *m_pObj;

};

#endif


