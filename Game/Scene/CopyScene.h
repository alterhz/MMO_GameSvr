#ifndef _COPYSCENE_
#define _COPYSCENE_

#include "Scene.h"

class CCopyScene : public CScene
{
public:
	CCopyScene();
	~CCopyScene();

	virtual bool OnRunCommand(ICommand *pCommand);

	virtual bool EnterScene(CObj *pObj);
	virtual bool LeaveScene(CObj *pObj);

public:
	virtual bool OnEnterScene(CObj *pObj);

};

#endif