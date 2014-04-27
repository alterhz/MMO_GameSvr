#include "Scene.h"


bool CScene::EnterScene(CObj *pObj)
{
	// 进入场景事件
	return OnEnterScene(pObj);
}

bool CScene::LeaveScene(CObj *pObj)
{
	// 离开场景事件
	return OnLeaveScene(pObj);
}
