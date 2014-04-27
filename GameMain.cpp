// MMO_GameSvr.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "SceneManager.h"

CSceneManager *s_pSceneManager = NULL;

bool IoTick(unsigned long tElapsed)
{
	static unsigned long tLast = 0;
	tLast += tElapsed;
	
	if (tLast < 3000)
	{
		return false;
	}

	tLast = 0;

	// 投递场景事件
	CommandEnterScene *pCommand = new CommandEnterScene;
	if (!pCommand)
	{
		return false;
	}
	
	if (s_pSceneManager)
	{
		CScene *pScene = s_pSceneManager->FindByTypeId(1001);
		if (pScene)
		{
			pScene->QueueCommand(pCommand);
		}

		pScene = s_pSceneManager->FindByTypeId(1002);
		if (pScene)
		{
			pScene->QueueCommand(pCommand);
		}
	}
	
	return true;
}

bool SysTick(unsigned long tElapsed)
{
	if (s_pSceneManager)
	{
		s_pSceneManager->DoTick(tElapsed);
	}

	return true;
}

bool UnitTest()
{
	s_pSceneManager = new CSceneManager;

	CScene *pScene = s_pSceneManager->CreateScene(SceneType_Comm);
	if (!pScene)
	{
		return false;
	}

	pScene->SetTypeId(1001);

	pScene = s_pSceneManager->CreateScene(SceneType_Copy);
	if (!pScene)
	{
		return false;
	}

	pScene->SetTypeId(1002);

	while (true)
	{
		Sleep(100);
		
		static unsigned long tLast = GetTickCount();
		unsigned long tNow = GetTickCount();

		unsigned long tElapsed = tNow-tLast;
		tLast = tNow;

		SysTick(tElapsed);
		IoTick(tElapsed);
	}

	return true;
}


int main(int argc, char* argv[])
{
	UnitTest();

	return 0;
}

