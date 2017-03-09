#include "Stadion.h"
#include <iostream>

CStadion::CStadion(void)
{
	for (int i=1; i<13; i++)
	
		{for (int j=1;j<101;j++)
	if(i==1)
			{
				m_pMiejsca[j]=new CMiejsce;
				m_pMiejsca[j]->m_iNumerKrzesla=j;
				m_pMiejsca[j]->m_iRzad=i;
	}
	else
	{ int k=i-1;
	  int l=100*k+j;
		m_pMiejsca[l]=new CMiejsce;
		m_pMiejsca[l]->m_iNumerKrzesla=j;
		m_pMiejsca[l]->m_iRzad=i;
	}
	}

}


CStadion::~CStadion(void)
{
		for (int k=1; k<13; k++)
		{for (int l=1; l<101; l++)
		{       m_pMiejsca[k*l]=NULL;
				delete m_pMiejsca[k*l];
				
		}}

}



void CStadion::SprawdzBilet(CJednorazowy* b1)
{
	if ( b1->m_bWejscie==1)
	b1->m_pSiedzienie->m_bStan=1;
}


