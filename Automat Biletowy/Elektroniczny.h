#pragma once
#include "bilet.h"
#include "Kibic.h"

class CElektroniczny :
	public CBilet
{
public:
	CElektroniczny(void);
	~CElektroniczny(void);
	int m_iKodBiletu;
	CKibic* m_pMojKibic;
};

