#pragma once
#include "Opowiadacz.h"
#include <iostream>

struct Pos
{
	size_t X;
	size_t Y;
};

enum Typ
{
	ZWIERZE = 1,
	ROSLINA = 2
};

enum Kierunki
{
	UP = 1,
	DOWN = 0,
	LEFT = 2,
	RIGHT = 3,
	NONE = 4

};

enum Specjalna_Akcja
{
	TARCZA = 0,
	NIESMIERTELNOSC = 1,
	BYCIE_STUDENTEM = 2

};

class Byt
{
	friend class Zapis;
protected:
	Kierunki nastepnykier;
	Pos pozycja;
	int wiek;
	int inicjatywa;
	int sila;
	Typ typorganizmu;
	std::string nazwaorganizmu;

public:
	virtual void Akcja() = 0;
	virtual void Kolizja(Pos pozycjax) = 0;
	virtual char Rysowanie() = 0;
	void SetWiek(int wiek_tmp);
	int  GetWiek() const;
	int  GetInicjat() const;
	int  GetSila() const;
	void SetSila(int sila_tmp);
	Pos Daj_Pozycje();
	void Set_Pozycje(Pos setpozycja);
	Byt(int wiek_tmp, int sila_tmp, int inicjat_tmp, Pos tmp, Typ typorganizmux, std::string nazwa_tmp);
	Typ GetTyp();
	void SetKierunek(Kierunki kierunekx);
	virtual void SetUmiejetnosc(Specjalna_Akcja akcja);
	std::string GetNazwa();

};