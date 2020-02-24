#pragma once
#include "Byt.h"

#include <vector>
#include <iostream>
#include <list>


class Swiat
{
	friend class Zapis;
private:
	std::vector<std::vector<Byt*>> tab;
	std::list<Byt*> lista;
	std::list<Byt*> garbagelist;
	size_t rozmiar;
	size_t rozmiar2;
	int Ile_Organizmow;
	Opowiadacz* refopowiadacz;
public:
	Swiat();
	Swiat(size_t size, size_t size2, Opowiadacz* tmp_opowiadacz);
	~Swiat();
	size_t Getrozmiar();
	size_t Getrozmiar2();
	void WykonajTure();
	void RysujSwiat();
	void WstawOrganizm(Pos poz, Byt* do_wstawienia);
	void UsunOrganizm(Pos poz);
	void ZabijOrganizm(Pos poz);
	void WstawiZabijOrganizm(Byt* do_zabicia, Byt* do_wstawienia);
	Byt** WezPole(size_t x, size_t y);
	Pos ZnajdzNajblizszy(Pos pozyciapocz, char zwierzekon);
	void Garbage();
	void AktywujUmiejetnosc(Specjalna_Akcja akcja);
	void KazRuszycCzlowiekowi(Kierunki kierx);
	void DodajZdarzenie(std::string zdarzenie);

};