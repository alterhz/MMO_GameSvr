
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

	// 创建创建对象
	CScene * CreateScene(SceneType eTypeScene);
	// 销毁场景对象
	void DestoryScene(int nIndex);
	// 查找场景对象
	CScene * Find(int nIndex);
	// 查找场景
	CScene * FindByTypeId(int nTypeId);
	// tick循环
	bool DoTick(unsigned long nElapsed);

private:
	int m_nAllocIndex;
	std::map<int, CScene *> m_mapScene;

};


#endif

