#include "CommScene.h"
#include <iostream>

CCommScene::CCommScene() : CScene(SceneType_Comm)
{

}

CCommScene::~CCommScene()
{

}

bool CCommScene::OnRunCommand( ICommand *pCommand )
{
	if (!pCommand)
	{
		return false;
	}

	if (CommandType_EnterScene == pCommand->GetCommandType())
	{
		CommandEnterScene *pCommandEnterScene = dynamic_cast<CommandEnterScene *>(pCommand);
		if (pCommandEnterScene)
		{
			EnterScene(pCommandEnterScene->GetObj());
		}
	}

	return true;
}

bool CCommScene::EnterScene(CObj *pObj)
{
	std::cout << "进入普通地图" << std::endl;

	return CScene::EnterScene(pObj);
}

bool CCommScene::LeaveScene(CObj *pObj)
{
	std::cout << "离开地图" << std::endl;

	return CScene::LeaveScene(pObj);
}

bool CCommScene::OnEnterScene(CObj *pObj)
{
	std::cout << "已进入普通地图" << std::endl;
	return true;
}
