#ifndef _SCENE_
#define _SCENE_

#include "CommandManager.h"
#include "Obj.h"

enum SceneType
{
	SceneType_Null = 0,
	SceneType_Comm,		//��ͨ��ͼ
	SceneType_Copy,		//������ͼ
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


public:	//�����ӿ�
	virtual bool EnterScene(CObj *pObj);
	virtual bool LeaveScene(CObj *pObj);

protected:	//�¼��ӿ�
	virtual bool OnEnterScene(CObj *pObj) { return true; }
	virtual bool OnLeaveScene(CObj *pObj) { return true; }


public:
	// ����ִ��
	virtual bool DoTick(unsigned long nElapsed)
	{
		ICommand *pCommand = PopCommand();
		if (!pCommand)
		{
			return false;
		}

		return OnRunCommand(pCommand);;
	}
	// ִ��Command�¼�
	virtual bool OnRunCommand(ICommand *pCommand) = 0;

private:
	SceneType m_eTypeScene;
	int m_nIndex;	//Ψһ����
	int m_nTypeId;	//����ID

};

#endif
