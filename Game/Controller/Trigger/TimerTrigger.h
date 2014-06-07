
#ifndef _TIMERTRIGGER_
#define _TIMERTRIGGER_

#include "IBaseCtrl.h"

class CTimerTrigger : public ITrigger
{
public:
	CTimerTrigger();
	~CTimerTrigger();

public:
	virtual bool IsTriggered();
	virtual bool OnTick(unsigned int nElapsedTime);
	virtual bool OnCommand(ICommand *pCommand);

private:
	unsigned int m_nElapsedTime;	//���ŵ�ʱ��
	unsigned int m_nWaitTime;		//�ȴ�ʱ��

};


#endif

