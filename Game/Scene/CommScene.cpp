#include "CommScene.h"

bool CCommScene::DoTick( unsigned long nElapsed )
{
	ICommand *pCommand = PopCommand();

	if (pCommand)
	{
		
	}

	return true;
}
