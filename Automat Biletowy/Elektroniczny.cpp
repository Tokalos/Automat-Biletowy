#include "Elektroniczny.h"


CElektroniczny::CElektroniczny(void)
	: m_iKodBiletu(0)
{
	m_pMojKibic=new CKibic;
}


CElektroniczny::~CElektroniczny(void)
{
	m_pMojKibic=0;
	delete m_pMojKibic;
}
