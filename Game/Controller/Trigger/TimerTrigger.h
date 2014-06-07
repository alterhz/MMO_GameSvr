
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
	unsigned int m_nElapsedTime;	//流逝的时间
	unsigned int m_nWaitTime;		//等待时间

};


#endif

