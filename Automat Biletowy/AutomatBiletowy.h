#pragma once
#include "Klient.h"
#include "Stadion.h"
#include <iostream>
#include <stdlib.h>
#include "Jednorazowy.h"
#include "BiletyElektroniczne.h"
#include "Blad.h"

class CAutomatBiletowy
{
public:

	//konstruktor
	CAutomatBiletowy(void);
	~CAutomatBiletowy(void);


	//metody
	void PodajDane(void);
	void PodajMiejsce(void);
	void SprawdzMiejsce(void);
	void Zaplac(CBiletyElektroniczne *b);
	bool SprawdzMiejsce(CStadion s1);
	void Drukuj(CStadion s1);
	void WydajBilet(void);
	void Powitanie();
	void RodzajBiletu(CBiletyElektroniczne b1);
	void Miejsce(CStadion s1,CBiletyElektroniczne *b1);
	void Wejscie(CBiletyElektroniczne *b1);
	bool DoladujJednorazowy(CJednorazowyE *j1);
	bool DoladujOkresowy(COkresowy *o1);
	bool JestLiczba(char *l);
	
	
	//zmienne
	
	CKlient* m_pKlient;
	CJednorazowy* m_pBilet;

private:

	int m_iNumerMiejsca;
	int m_iRzad;
	int m_iNumerOkresowy;
	int m_iNumerJednorazowy;


	
};

