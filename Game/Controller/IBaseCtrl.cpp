#include "IBaseCtrl.h"

#include <iostream>

void IBaseCtrl::SetTokenName( const char *pTokenName )
{
	memcpy_s(m_szTokenName, sizeof(m_szTokenName), pTokenName, strlen(pTokenName)+1);
}
