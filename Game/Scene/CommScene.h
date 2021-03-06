#ifndef _COMMSCENE_
#define _COMMSCENE_

#include "Scene.h"

class CCommScene : public CScene
{
public:
	CCommScene();
	~CCommScene();

	virtual bool OnRunCommand(ICommand *pCommand);

	virtual bool EnterScene(CObj *pObj);
	virtual bool LeaveScene(CObj *pObj);

public:
	virtual bool OnEnterScene(CObj *pObj);

};

#endif