#pragma once
#include "Miejsce.h"
class CBilet
{
public:
	CBilet(void);
	~CBilet(void);
	int m_iNumer;
	float m_fCena;
	CMiejsce* m_pSiedzienie;
};

