#include "Byt.h"

void Byt::SetWiek(int wiek_tmp)
{
	wiek = wiek_tmp;
}



int Byt::GetWiek() const
{
	return wiek;
}

int Byt::GetInicjat() const
{
	return inicjatywa;
}

int Byt::GetSila() const
{
	return sila;
}

void Byt::SetSila(int sila_tmp)
{
	sila = sila_tmp;
}

Pos Byt::Daj_Pozycje()
{
	return pozycja;
}

void Byt::Set_Pozycje(Pos setpozycja)
{
	pozycja = setpozycja;
}




Byt::Byt(int wiek_tmp, int sila_tmp, int inicjat_tmp, Pos tmp, Typ typorganizmux, std::string nazwa_tmp) : nazwaorganizmu(nazwa_tmp), nastepnykier(NONE), wiek(wiek_tmp), inicjatywa(inicjat_tmp), sila(sila_tmp), pozycja(tmp), typorganizmu(typorganizmux)
{

}

Typ Byt::GetTyp()
{
	return typorganizmu;
}

void Byt::SetKierunek(Kierunki kierunekx)
{
	nastepnykier = kierunekx;
}

void Byt::SetUmiejetnosc(Specjalna_Akcja akcja)
{
}

std::string Byt::GetNazwa()
{
	return nazwaorganizmu;
}
