#include "Blad.h"


CBlad::CBlad(void)
:m_iKod(0)
,m_csOpis("brak bledow")
{
}

CBlad::CBlad(int kod,char* info)
:m_iKod(kod)
,m_csOpis(info)
{
	if(kod <0)
	{
		m_bJestBlad = true;
	}
}

CBlad::~CBlad(void)
{
}
