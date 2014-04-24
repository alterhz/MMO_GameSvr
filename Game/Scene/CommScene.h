#ifndef _COMMSCENE_
#define _COMMSCENE_

#include "IScene.h"

class CCommScene : public IScene
{
public:
	// ÐÄÌøÖ´ÐÐ
	virtual bool DoTick(unsigned long nElapsed);


};

#endif