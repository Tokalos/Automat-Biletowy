#include "Papierowy.h"


CPapierowy::CPapierowy(void)
{
	m_pCustomer=new CKlient;
}


CPapierowy::~CPapierowy(void)
{
	 m_pCustomer=0;
delete m_pCustomer;
}
