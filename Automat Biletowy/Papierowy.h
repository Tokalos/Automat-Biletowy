#pragma once
#include "bilet.h"
#include "Klient.h"
class CPapierowy :
	public CBilet
{
public:
	CPapierowy(void);
	~CPapierowy(void);
	CKlient *m_pCustomer;
};

