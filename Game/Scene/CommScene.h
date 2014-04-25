#ifndef _COMMSCENE_
#define _COMMSCENE_

#include "IScene.h"

class CCommScene : public IScene
{
public:
	virtual bool OnRunCommand(ICommand *pCommand);


};

#endif