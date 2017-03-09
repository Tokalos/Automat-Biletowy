#pragma once
#include <iostream>

using namespace std;

class CBlad
{
private:
	int m_iKod;
	char* m_csOpis;
	bool m_bJestBlad;

public:
	CBlad(void);
	CBlad(int kod,char* info); 
	~CBlad(void);



	inline bool Ostrzezenie() {return m_iKod!=0;} 
	inline bool Blad() {return m_iKod<0;}
	inline int DajKodBledu() {return m_iKod;}
	inline bool JestBlad() {return m_bJestBlad;}

	friend ostream &operator<<(ostream &os,const CBlad &blad); 
};

