#include <iostream>
#include <stdlib.h>
#include "locale.h"
#include "AutomatBiletowy.h"
#include "Stadion.h"
#include <cstdlib>





int main()
{

using namespace std;

setlocale(LC_ALL,"polish");
CStadion s1;
CAutomatBiletowy a1;
CBiletyElektroniczne b1;

a1.Powitanie(); //Pierwszy kontakt z u¿ytokwnikiem

a1.RodzajBiletu(b1); // metoda wykorzystuje duzo innych metod pozosta³ych z tej klasy. Pyta u¿ytkownika o rodzaj biletu
					// i jeœli odpowie ze ma bilet elektroniczny pyta baze danych o to jaki to jest bilet i jakiego ma pod soba uzytkownika

a1.Miejsce(s1,&b1); //sprawdza dostepnosc miejsca, potem sprawdza bilet i jesli wystepuje potrzeba zaplaty wywoluje metode zaplac

a1.Wejscie(&b1);// kontatktuje sie z miejscem przypisanym do biletu sprawdza czy jest ono wolne(kolejny test) i jesli jest wolne wpuszcza.

system("PAUSE");

return 0;
 
}


