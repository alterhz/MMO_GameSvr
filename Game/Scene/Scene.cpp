#include "Scene.h"


bool CScene::EnterScene(CObj *pObj)
{
	// ���볡���¼�
	return OnEnterScene(pObj);
}

bool CScene::LeaveScene(CObj *pObj)
{
	// �뿪�����¼�
	return OnLeaveScene(pObj);
}
