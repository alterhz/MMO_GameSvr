#ifndef _SCENE_
#define _SCENE_

#include "CommandManager.h"
#include "Obj.h"

enum SceneType
{
	SceneType_Null = 0,
	SceneType_Comm,		//普通地图
	SceneType_Copy,		//副本地图
};

class CScene : public CommandManager
{
public:
	CScene(SceneType eTypeScene) : m_eTypeScene(eTypeScene) { }
	virtual ~CScene() { }
	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int GetIndex() const { return m_nIndex; }
	void SetTypeId(int nTypeId) { m_nTypeId = nTypeId; }
	int GetTypeId() const { return m_nTypeId; }


public:	//函数接口
	virtual bool EnterScene(CObj *pObj);
	virtual bool LeaveScene(CObj *pObj);

protected:	//事件接口
	virtual bool OnEnterScene(CObj *pObj) { return true; }
	virtual bool OnLeaveScene(CObj *pObj) { return true; }


public:
	// 心跳执行
	virtual bool DoTick(unsigned long nElapsed)
	{
		ICommand *pCommand = PopCommand();
		if (!pCommand)
		{
			return false;
		}

		return OnRunCommand(pCommand);;
	}
	// 执行Command事件
	virtual bool OnRunCommand(ICommand *pCommand) = 0;

private:
	SceneType m_eTypeScene;
	int m_nIndex;	//唯一索引
	int m_nTypeId;	//场景ID

};

#endif
