#pragma once
#include "Miejsce.h"
#include "Jednorazowy.h"
#include "JednorazowyE.h"
#include "Okresowy.h"

class CStadion
{
public:
	CStadion(void);
	~CStadion(void);
	CMiejsce* m_pMiejsca[12000];
//void SprawdzMiejsce(CAutomatBiletowy a1);
	void SprawdzBilet(CJednorazowy* b1);


};

/*CJednorazowyE* b2, COkresowy* b3*/