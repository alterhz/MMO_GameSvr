#include "SceneManager.h"


CSceneManager::CSceneManager()
{
	m_nAllocIndex = 0;
}

CSceneManager::~CSceneManager()
{

}

CScene * CSceneManager::CreateScene( SceneType eTypeScene )
{
	switch (eTypeScene)
	{
	case SceneType_Comm:
		{
			CCommScene *pCommScene = new CCommScene;
			if (!pCommScene)
			{
				return NULL;
			}

			pCommScene->SetIndex(++m_nAllocIndex);

			m_mapScene.insert(std::make_pair(pCommScene->GetIndex(), pCommScene));

			return pCommScene;
		}
		break;
	case SceneType_Copy:
		{
			CCopyScene *pCopyScene = new CCopyScene;
			if (!pCopyScene)
			{
				return NULL;
			}

			pCopyScene->SetIndex(++m_nAllocIndex);

			m_mapScene.insert(std::make_pair(pCopyScene->GetIndex(), pCopyScene));

			return pCopyScene;
		}
		break;
	default:
		{
			return NULL;
		}
	}
}

void CSceneManager::DestoryScene( int nIndex )
{
	CScene *pScene = Find(nIndex);
	if (!pScene)
	{
		return ;
	}

	m_mapScene.erase(nIndex);

	delete pScene;
	pScene = NULL;
}

CScene * CSceneManager::Find( int nIndex )
{
	std::map<int, CScene *>::iterator it = m_mapScene.find(nIndex);
	if (it != m_mapScene.end())
	{
		return it->second;
	}

	return NULL;
}

CScene * CSceneManager::FindByTypeId( int nTypeId )
{
	std::map<int, CScene *>::iterator it = m_mapScene.begin();
	for (; it!=m_mapScene.end(); ++it)
	{
		if (it->second->GetTypeId() == nTypeId)
		{
			return it->second;
		}
	}

	return NULL;
}

bool CSceneManager::DoTick( unsigned long nElapsed )
{
	std::map<int, CScene *>::iterator it = m_mapScene.begin();
	for (; it!=m_mapScene.end(); ++it)
	{
		it->second->DoTick(nElapsed);
	}

	return true;
}
