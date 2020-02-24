#pragma once
#include "Swiat.h"
#include <windows.h>

enum Decyzje
{
	CZY_RUSZYC = 1,
	CZY_ROZMNOZYC = 2,
	//CZY_ZGINAC = 3
	CZY_WALCZYC = 3,
	CZY_PRZEPROWADZIC_WALKE = 4,
	CZY_WYKONAC_RUCH = 5
};




class Organizm : public Byt
{
	friend class Zapis;
protected:
	Swiat *referencja;
	Pos WybiezPole(Swiat* ref, Pos poz, Kierunki kierunek);

public:
	Organizm(Pos tmp, int sila_tmp, int inicjat, int wiek, Typ typorganizmux, Swiat* jakiswiat, std::string nazwa_tmp);
	virtual Pos PoczatekAkcji();
	virtual Pos PoczatekAkcji(Kierunki jakiskierunek);
	virtual bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax);
	virtual Byt* StworzDziecko(Pos pozycjay) = 0;
	virtual char Rysowanie() = 0;
	virtual void Rozmnoz(Pos pozycjax) = 0;
	virtual void Walcz(Pos pozycjax) = 0;

	static Kierunki wybierzkierunek();

};