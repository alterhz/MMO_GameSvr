
#ifndef _IBASECTRL_
#define _IBASECTRL_

#include "ICommand.h"

#define MAX_CTRL_NAME_LENGTH		(32)

class IBaseCtrl
{
public:
	IBaseCtrl()
	{
		m_szTokenName[0] = '\0';
	}

public:
	const char * GetTokenName() const { return m_szTokenName; }
	void SetTokenName(const char *pTokenName);

private:
	char m_szTokenName[MAX_CTRL_NAME_LENGTH];

};

class ITrigger : public IBaseCtrl
{
public:
	ITrigger()
	{
		m_bTriggered = false;
	}

public:
	virtual bool IsTriggered() = 0;
	virtual bool OnTick(unsigned int nElapsedTime) = 0;
	virtual bool OnCommand(ICommand *pCommand) = 0;

protected:
	void SetTriggered(bool b = true) { m_bTriggered = b; }
	bool GetTriggered() const { return m_bTriggered; }

private:
	bool m_bTriggered;
};

class IAction : public IBaseCtrl
{
public:
	virtual bool OnTick(unsigned int nElapsedTime) = 0;

};

class IFilter : public IBaseCtrl
{
public:
	virtual bool OnTick(unsigned int nElapsedTime) = 0;
	virtual bool OnCommand(ICommand *pCommand) = 0;

};

#endif