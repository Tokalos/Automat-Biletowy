#pragma once
#include"Elektroniczny.h"
#include "JednorazowyE.h"
#include "Okresowy.h"
#include <string.h>
#include <stdio.h>
class CBiletyElektroniczne
{
public:
	CBiletyElektroniczne(void);
	~CBiletyElektroniczne(void);
   COkresowy* m_pOkresowe[3];
   CJednorazowyE * m_pJednorazowe[3];

};

