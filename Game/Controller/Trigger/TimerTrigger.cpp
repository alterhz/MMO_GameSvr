#include "TimerTrigger.h"

CTimerTrigger::CTimerTrigger()
{
	m_nElapsedTime = 0;
	m_nWaitTime = 0;
}

CTimerTrigger::~CTimerTrigger()
{

}

bool CTimerTrigger::IsTriggered()
{
	return true;
}

bool CTimerTrigger::OnTick( unsigned int nElapsedTime )
{
	if (GetTriggered())
	{
		return true;
	}

	m_nElapsedTime += nElapsedTime;

	if (m_nElapsedTime >= m_nWaitTime)
	{
		SetTriggered();
	}

	return true;
}

bool CTimerTrigger::OnCommand( ICommand *pCommand )
{
	return true;
}
