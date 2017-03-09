#include "BiletyElektroniczne.h"



CBiletyElektroniczne::CBiletyElektroniczne(void)
{
      for (int i=1 ;i<3;i++)
	{m_pOkresowe[i]= new COkresowy;
	  m_pJednorazowe[i]=new CJednorazowyE;}
	 strcpy_s (m_pOkresowe[1]->m_pMojKibic->m_sImie,"Luke");
	strcpy_s (m_pOkresowe[1]->m_pMojKibic->m_sNazwisko,"Skywalker");
	 m_pOkresowe[1]->m_iIloscWejsc=0;
	 m_pOkresowe[1]->m_iKodBiletu=2;
	 strcpy_s(m_pOkresowe[2]->m_pMojKibic->m_sImie,"Han");
	 strcpy_s(m_pOkresowe[2]->m_pMojKibic->m_sNazwisko,"Solo");
	 m_pOkresowe[2]->m_iIloscWejsc=2;
	 m_pOkresowe[2]->m_iKodBiletu=4;
	 strcpy_s(m_pJednorazowe[1]->m_pMojKibic->m_sImie,"Darth");
	 strcpy_s(m_pJednorazowe[1]->m_pMojKibic->m_sNazwisko,"Vader");
	 m_pJednorazowe[1]->m_bWejscie=0;
	 m_pJednorazowe[1]->m_iKodBiletu=1;
	 strcpy_s(m_pJednorazowe[2]->m_pMojKibic->m_sImie,"Lando");
	 strcpy_s(m_pJednorazowe[2]->m_pMojKibic->m_sNazwisko,"Calrissian");
	  m_pJednorazowe[2]->m_bWejscie=1;
	  m_pJednorazowe[2]->m_iKodBiletu=3;
}


CBiletyElektroniczne::~CBiletyElektroniczne(void)
{
	for (int i=0; i<2 ;i++)
	{
		m_pJednorazowe[i]=0;
		delete	m_pJednorazowe[i];
		m_pOkresowe[i]=0;
		delete	m_pOkresowe[i];
	}
}


