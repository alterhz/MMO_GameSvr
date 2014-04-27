#include "CopyScene.h"
#include <iostream>

CCopyScene::CCopyScene() : CScene(SceneType_Copy)
{

}

CCopyScene::~CCopyScene()
{

}

bool CCopyScene::OnRunCommand( ICommand *pCommand )
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

bool CCopyScene::EnterScene( CObj *pObj )
{
	std::cout << "���븱����ͼ" << std::endl;

	return CScene::EnterScene(pObj);
}

bool CCopyScene::LeaveScene( CObj *pObj )
{

	return CScene::LeaveScene(pObj);
}

bool CCopyScene::OnEnterScene(CObj *pObj)
{
	std::cout << "�Ѿ����븱����ͼ��" << std::endl;
	return true;
}

