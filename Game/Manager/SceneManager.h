
#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include <map>
#include "CommScene.h"
#include "CopyScene.h"

class CSceneManager
{
public:
	CSceneManager();
	
	~CSceneManager();

	// ������������
	CScene * CreateScene(SceneType eTypeScene);
	// ���ٳ�������
	void DestoryScene(int nIndex);
	// ���ҳ�������
	CScene * Find(int nIndex);
	// ���ҳ���
	CScene * FindByTypeId(int nTypeId);
	// tickѭ��
	bool DoTick(unsigned long nElapsed);

private:
	int m_nAllocIndex;
	std::map<int, CScene *> m_mapScene;

};


#endif

