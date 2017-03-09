#include "AutomatBiletowy.h"


using namespace std;

CAutomatBiletowy::CAutomatBiletowy(void)
	:m_iNumerOkresowy(0),
	m_iNumerJednorazowy(0)
{
	m_pKlient=new CKlient;
	m_pKlient->m_fPieniadze=50;
}

CAutomatBiletowy::~CAutomatBiletowy(void)
{
	delete m_pKlient;
	m_pKlient=0;

}

void CAutomatBiletowy::PodajDane(void)
{
	char b[80];
	char c[80];
	cout<<"Podaj Imiê: ";
	do
	{	try
			{
				cin>>b;

			if(strlen(b)>20)
				{
					throw CBlad(-103,"Za dlugie imie!");
				}
			if(JestLiczba(b))
				{	
					throw CBlad(-104,"Czy twoje imie to liczba?");
				}
			if(strlen(b)==0)
			{
				throw CBlad(-105,"Brak wpisanego imienia");
			}
			strcpy_s(m_pKlient->m_sImie,b);
			}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj poprawnie imiê masz do wykorzystania 20 znaków."<<endl;
				cout<<endl;
			}
		}}
		while(strlen(b)>20 || JestLiczba(b)==true || strlen(b)==0);

	cout<<"Podaj Nazwisko: ";
	do
	{
		try
			{
				cin>>c;
		if(strlen(c)>20)
				{
					throw CBlad(-103,"Za dlugie Nazwisko!");
				}
			if(JestLiczba(c))
				{	
					throw CBlad(-104,"Czy twoje nazwisko to liczba?");
				}
			if(strlen(c)==0)
			{
				throw CBlad(-105,"Brak wpisanego nazwiska");
			}
			strcpy_s(m_pKlient->m_sNazwisko,c);
		}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj poprawne nazwisko masz do wykorzystania 20 znaków."<<endl;
				cout<<endl;
			}
		}}
		while(strlen(c)>20 || JestLiczba(c)==true || strlen(c)==0);
} //szcztuje dane od uzytkownika imie i nazwisko, tylko bilet jednorazowy

void CAutomatBiletowy::PodajMiejsce(void)
{
	char b[80];
	char c[80];
	cout<<"Podaj Rz¹d: ";
	do
	{
		try
			{
				cin>>b;
			if(!JestLiczba(b))
				{
					throw CBlad(-101,"Niewlasciwa liczba!");
				}
			if(JestLiczba(b))
				{	if(atoi(b)==0 || atoi(b)>12 || atoi(b)<0)
					throw CBlad(-102," Nie ma takiego rzedu");
				}
				m_iRzad=atoi(b);
			}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj ponownie rzad stadionu, przypominam od 1 do 12."<<endl;
				cout<<endl;
			}
		}}
		while(JestLiczba(b)!=true || atoi(b)==0 || atoi(b)>12 || atoi(b)<0);

    cout<<"Podaj Miejsce: ";
	do
	{ 
		try
			{
				cin>>c;
			if(!JestLiczba(c))
				{
					throw CBlad(-101,"Niewlasciwa liczba!");
				}
			if(JestLiczba(c))
				{	if(atoi(c)==0 || atoi(c)>100 || atoi(c)<0)
					throw CBlad(-102," Nie ma takiego miejsca");
					
				}
				m_iNumerMiejsca=atoi(c);
			}

		catch(CBlad d)
		{ cout<<endl;

				if(d.JestBlad())
				{
					cerr<<"BLAD "<<d<<endl;
					cerr<<"Podaj ponownie miejsce w rz¹dzie stadionu, przypominam od 1 do 100."<<endl;
					cout<<endl;
				}
		}
	}
		while(atoi(c)==0 || atoi(c)>100 || atoi(c)<0 || JestLiczba(b)!=true);

} //szczytuje jakie miejsce chce zajac uzytkownik

bool CAutomatBiletowy::SprawdzMiejsce(CStadion s1)
{
	if (s1.m_pMiejsca[m_iNumerMiejsca*m_iRzad]->m_bStan==0)
	{
		//cout<<"Wolne Miejsce"<<endl;
		return true ;
	}
	else
	{
		//cout<<"Zajete Miejsce"<<endl;
		return false;
	}
} // 

void CAutomatBiletowy::Zaplac(CBiletyElektroniczne *b)
{
	float temp;
	cout<<"Zaplac!"<<endl;
	if(m_iNumerJednorazowy!=0)
		{	cout<<"Elektroniczny jednorazowy: "<<endl;
			temp=b->m_pJednorazowe[m_iNumerJednorazowy]->m_pMojKibic->m_fPieniadze-b->m_pJednorazowe[m_iNumerJednorazowy]->m_fCena;
			b->m_pJednorazowe[m_iNumerJednorazowy]->m_pMojKibic->m_fPieniadze=temp;
			cout<<"Zostanie ci tylko: "<<b->m_pJednorazowe[m_iNumerJednorazowy]->m_pMojKibic->m_fPieniadze<<"z³"<<endl;
	}
		if(m_iNumerOkresowy!=0)
		{	cout<<"Elektroniczny okresowy: "<<endl;
			temp=b->m_pOkresowe[m_iNumerOkresowy]->m_pMojKibic->m_fPieniadze-((b->m_pOkresowe[m_iNumerOkresowy]->m_iIloscWejsc)*b->m_pOkresowe[m_iNumerOkresowy]->m_fCena);
			b->m_pOkresowe[m_iNumerOkresowy]->m_pMojKibic->m_fPieniadze=temp;
			cout<<"Zostanie ci tylko: "<<b->m_pOkresowe[m_iNumerOkresowy]->m_pMojKibic->m_fPieniadze<<"z³"<<endl;
		}
	if(m_iNumerJednorazowy==0 && m_iNumerOkresowy==0)
		{
			temp=(m_pBilet->m_pCustomer->m_fPieniadze-m_pBilet->m_fCena);
			m_pBilet->m_pCustomer->m_fPieniadze=temp;
			cout<<"Zostanie ci tylko: "<<m_pBilet->m_pCustomer->m_fPieniadze<<"z³"<<endl;
		}
	
	cout<<"Dziekuje!"<<endl;
}

void CAutomatBiletowy::Drukuj(CStadion s1)
{
	m_pBilet=new CJednorazowy;
	m_pBilet->m_pSiedzienie=s1.m_pMiejsca[m_iNumerMiejsca+(m_iRzad-1)*100];
	m_pBilet->m_bWejscie=1;
	m_pBilet->m_iNumer=123;
}

void CAutomatBiletowy::WydajBilet(void)
{
	m_pBilet->m_pCustomer=m_pKlient;
}

void CAutomatBiletowy::Powitanie()
{
	cout<<"Witaj!"<<endl<<"Automat Biletowy EX800!"<<endl;
	cout<<"Prosze postêpuj zgodnie z instrukcjami wyœwietlonymi na ekranie"<<endl;

}

void CAutomatBiletowy::RodzajBiletu(CBiletyElektroniczne b1)
{
	char c[40];
	char b[40];
	char c1[10];
	char d1[10];
cout<<"Czy masz bilet elektroniczny?(t/n)";
	do 
	{
		cin>>c;
if(c[0]=='t' || c[0]=='T')
{
		cout<<"Czy masz bilet okresowy?";
		
		do {
		cin>>b;
		if(b[0]=='t' || b[0]=='T')
		{
		cout<<"Podaj numer biletu okresowego 1,2";
		do {try
			{
				cin>>d1;
			if(!JestLiczba(d1))
				{
					throw CBlad(-101,"Niewlasciwa liczba!");
				}
			if(JestLiczba(d1))
				{	if(atoi(d1)==0 || atoi(d1)>2 || atoi(d1)<0)
					throw CBlad(-102," Nie ma takiego biletu");
				}
				m_iNumerOkresowy=atoi(d1);
			}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj ponownie rzad stadionu, przypominam od 1 do 12."<<endl;
				cout<<endl;
			}
		}}
		while(JestLiczba(d1)!=true || atoi(d1)==0 || atoi(d1)>2 || atoi(d1)<0);
		
		cout<<b1.m_pOkresowe[m_iNumerOkresowy]->m_pMojKibic->m_sImie<<endl;
		cout<<b1.m_pOkresowe[m_iNumerOkresowy]->m_pMojKibic->m_sNazwisko<<endl;
		}

		else 
		{  try
			{	if(b[0]=='n' || b[0]=='N')
				{
					cout<<"Podaj numer biletu jednorazowego 1,2";
			do{		try
			{
				cin>>c1;
			if(!JestLiczba(c1))
				{
					throw CBlad(-101,"Niewlasciwa liczba!");
				}
			if(JestLiczba(c1))
				{	if(atoi(c1)==0 || atoi(c1)>2 || atoi(c1)<0)
					throw CBlad(-102," Nie ma takiego biletu");
				}
				m_iNumerJednorazowy=atoi(c1);
			}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj ponownie rzad stadionu, przypominam od 1 do 12."<<endl;
				cout<<endl;
			}
		}}
		while(JestLiczba(c1)!=true || atoi(c1)==0 || atoi(c1)>2 || atoi(c1)<0);
					cout<<b1.m_pJednorazowe[m_iNumerJednorazowy]->m_pMojKibic->m_sImie<<endl;
					cout<<b1.m_pJednorazowe[m_iNumerJednorazowy]->m_pMojKibic->m_sNazwisko<<endl;
				

				}
			else throw CBlad(-106,"Bledny zapis");
		}
		catch(CBlad d)
				{
					 cout<<endl;
				 	if(d.JestBlad())
									{
									cerr<<"BLAD "<<d<<endl;
									cerr<<"Podaj ponownie literki"<<endl;
									cout<<endl;
									}
				}

		}

	}while(b[0]!='t' && b[0]!='T'&& b[0]!='n' && b[0]!='N');
}
else
{ try 
	{	if(c[0]=='n' || c[0]=='N')
		{	PodajDane();
			cout<<m_pKlient->m_sImie<<endl;
			cout<<m_pKlient->m_sNazwisko<<endl;
			m_pBilet=new CJednorazowy;
			m_pBilet->m_iNumer=123;
			WydajBilet();
		}
	else throw CBlad(-106,"Bledny zapis");
		}
	catch(CBlad d)
	{
		 cout<<endl;
		   	if(d.JestBlad())
				{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj ponownie literki"<<endl;
				cout<<endl;
				}
			}
		}
	}
while(c[0]!='t' && c[0]!='T' && c[0]!='n' && c[0]!='N');


}

void CAutomatBiletowy::Miejsce(CStadion s1, CBiletyElektroniczne *b1)
{
	do {
	
		PodajMiejsce();
			if(SprawdzMiejsce(s1)==false)
				cout<<"Zajete Miejsce "<<endl;
       }
while (SprawdzMiejsce(s1)==false);

if (SprawdzMiejsce(s1)==true)
	{ 
		cout<<"Miejsce, które wybra³eœ jest wolne "<<endl;
		
		if(m_iNumerOkresowy!=0)
			{
				if(b1->m_pOkresowe[m_iNumerOkresowy]->m_iKodBiletu==2 || b1->m_pOkresowe[m_iNumerOkresowy]->m_iKodBiletu==4)
			{
				if(b1->m_pOkresowe[m_iNumerOkresowy]->m_iIloscWejsc==0)
				{	DoladujOkresowy(b1->m_pOkresowe[m_iNumerOkresowy]);
					Zaplac(b1);
				}

				b1->m_pOkresowe[m_iNumerOkresowy]->m_pSiedzienie=s1.m_pMiejsca[m_iNumerMiejsca+(m_iRzad-1)*100];
				b1->m_pOkresowe[m_iNumerOkresowy]->m_pSiedzienie->m_bStan=1;
				}}
			else
{if(m_iNumerJednorazowy!=0)
{
if(b1->m_pJednorazowe[m_iNumerJednorazowy]->m_iKodBiletu==1 || b1->m_pJednorazowe[m_iNumerJednorazowy]->m_iKodBiletu==3)
{   if(b1->m_pJednorazowe[m_iNumerJednorazowy]->m_bWejscie==0)
	{
		DoladujJednorazowy(b1->m_pJednorazowe[m_iNumerJednorazowy]);
		Zaplac(b1);
}
		b1->m_pJednorazowe[m_iNumerJednorazowy]->m_pSiedzienie=s1.m_pMiejsca[m_iNumerMiejsca+(m_iRzad-1)*100];
		b1->m_pJednorazowe[m_iNumerJednorazowy]->m_pSiedzienie->m_bStan=1;
}}
}
if(m_iNumerOkresowy ==0 && m_iNumerJednorazowy==0)
{ 
	Zaplac(b1);
	m_pBilet->m_pSiedzienie=s1.m_pMiejsca[m_iNumerMiejsca+(m_iRzad-1)*100];
	m_pBilet->m_pSiedzienie->m_bStan=1;
	m_pBilet->m_bWejscie=0;
}

}
}

void CAutomatBiletowy::Wejscie(CBiletyElektroniczne *b1)
{
	if(m_iNumerJednorazowy!=0)
	
		{
			if(b1->m_pJednorazowe[m_iNumerJednorazowy]->m_iKodBiletu==1 || b1->m_pJednorazowe[m_iNumerJednorazowy]->m_iKodBiletu==3)
			
			{
				if(b1->m_pJednorazowe[m_iNumerJednorazowy]->m_pSiedzienie->m_bStan==0)
						cout<<"Jednorazowy Dalej Wolne"<<endl;
				else 
			{
						cout<<endl<<"Jednorazowy Wejdz Wolne Miejsce"<<endl;
				b1->m_pJednorazowe[m_iNumerJednorazowy]->m_bWejscie=0; //sprawdzanie czy jest wazny
			
				}
			}
	}
else 
	{
		if(m_iNumerOkresowy!=0)
		{
			if(b1->m_pOkresowe[m_iNumerOkresowy]->m_pSiedzienie->m_bStan==0)
				
					cout<<"Okresowy Dalej Wolne"<<endl;
			else 
				{
				cout<<endl<<"Okresowy Wejdz Wolne Miejsce"<<endl;
				b1->m_pOkresowe[m_iNumerOkresowy]->m_iIloscWejsc--;//sprawdzanie ilosci wejsc
				
				}
				
		}
if(m_iNumerOkresowy==0 && m_iNumerJednorazowy==0)
	{	
		if(m_pBilet->m_pSiedzienie->m_bStan==0)
		cout<<"Jednorazowy papierowy Dalej Wolne"<<endl;
		else 
		cout<<endl<<"Jednorazowy papierowy Wejdz Wolne Miejsce"<<endl;
	}
	}
}

bool CAutomatBiletowy::DoladujJednorazowy(CJednorazowyE *j1)
{
	if(j1->m_bWejscie==0)
	{
	j1->m_bWejscie=1;
	cout<<"Musisz do³adowaæ twój bilet nie jest wa¿ny."<<endl;
	return true;
	}
	else 
	return false;
}

bool CAutomatBiletowy::DoladujOkresowy(COkresowy *o1)
{
	if(o1->m_iIloscWejsc==0)
	{
	char b[20];
	cout<<"Twoj Bilet okresowy nie ma dostatecznie wielu wejsc. Musisz doladowac"<<endl;
	cout<<"Podaj ile chcesz doladowac(0-12):";
	do
	{
		try
			{
				cin>>b;
			if(!JestLiczba(b))
				{
					throw CBlad(-101,"Niewlasciwa liczba!");
				}
			if(JestLiczba(b))
				{	if(atoi(b)==0 || atoi(b)>12 || atoi(b)<0)
					throw CBlad(-102," Nie przewidujemy takiego do³adowania");
				}

				o1->m_iIloscWejsc=atoi(b);					
			}

		catch(CBlad d)
	   { 
		   cout<<endl;
		   	if(d.JestBlad())
			{
				cerr<<"BLAD "<<d<<endl;
				cerr<<"Podaj ponownie ile chcesz do³adowaæ(0 do 12)"<<endl;
				cout<<endl;
			}
		}}
		while(JestLiczba(b)!=true || atoi(b)==0 || atoi(b)>12 || atoi(b)<0);
	return true;
	}
	else 
	return false;
}

bool CAutomatBiletowy::JestLiczba(char *l)
{
	if (*l == '0')
	{
		return true;
	}

	if(atoi(l) == 0)
	{
		return false;
	}
	else

	{
		return true;
	}

}

ostream &operator<<(ostream &os,const CBlad &blad)
{

	cout<<blad.m_iKod<<": "<<blad.m_csOpis<<endl;

	return os;
}