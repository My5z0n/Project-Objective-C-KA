#include "Swiat.h"

#include <algorithm>


bool comparison(const Byt* node1, const Byt* node2)
{
	if (node1->GetInicjat() > node2->GetInicjat()) return true;
	if (node1->GetInicjat() == node2->GetInicjat()) return node1->GetWiek() > node2->GetWiek();

	return false;
}

Swiat::Swiat()
{

}

Swiat::Swiat(size_t size, size_t size2, Opowiadacz* tmp_opowiadacz) : rozmiar(size), rozmiar2(size2), lista(), refopowiadacz(tmp_opowiadacz)
{
	std::vector<Byt*> subarray;
	subarray.assign(size2, nullptr);
	tab.assign(size, subarray);
	rozmiar = size;
}


Swiat::~Swiat()
{
}

size_t Swiat::Getrozmiar()
{
	return rozmiar;
}

size_t Swiat::Getrozmiar2()
{
	return rozmiar2;
}

void Swiat::Garbage()
{

	for (auto &v : garbagelist)
	{
		delete v;
		v = nullptr;

	}
}
void Swiat::AktywujUmiejetnosc(Specjalna_Akcja akcja) {
	bool test = 0;
	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{

			}
			else
			{
				if (j->Rysowanie() == '@')
				{
					(j)->SetUmiejetnosc(akcja);
					test = 1;

				}

			}
		}
	}
	if (test == 0)
		throw "Nie ma czlowieka !";

}

void Swiat::KazRuszycCzlowiekowi(Kierunki kierx)
{

	bool test = 0;
	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{
				//....
			}
			else
			{
				if (j->Rysowanie() == '@')
				{
					(j)->SetKierunek(kierx);
					test = 1;

				}

			}
		}
	}
	if (test == 0)
		throw "Nie ma czlowieka!";

}

void Swiat::DodajZdarzenie(std::string zdarzenie)
{
	refopowiadacz->Dodaj(zdarzenie);
}

// Wykonuje jedn¹ turê
void Swiat::WykonajTure()
{
	lista.resize(0);

	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{
				//...
			}
			else
			{
				lista.push_back(j);

			}
		}
	}
	garbagelist.resize(0);

	lista.sort(comparison);

	for (auto i = lista.begin(); i != lista.end(); i++)
	{
		(*i)->Akcja();
	}


	Garbage();


	lista.resize(0);
	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{
				//....
			}
			else
			{
				lista.push_back(j);
			}
		}
	}

	lista.sort(comparison);

	for (auto i = lista.begin(); i != lista.end(); i++)
	{
		(*i)->SetWiek((*i)->GetWiek() + 1);
	}
}


void Swiat::RysujSwiat()
{
	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{
				std::cout << ".";
			}
			else
			{
				std::cout << j->Rysowanie();
			}

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Swiat::WstawOrganizm(Pos poz, Byt* do_wstawinia)
{
	Byt** pole = WezPole(poz.X, poz.Y);
	*pole = do_wstawinia;

}

void Swiat::UsunOrganizm(Pos poz)
{
	Byt** pole = WezPole(poz.X, poz.Y);
	*pole = nullptr;

}

void Swiat::ZabijOrganizm(Pos poz)
{

	Byt** pole = WezPole(poz.X, poz.Y);
	Byt* do_zabicia = *pole;

	garbagelist.push_back(*pole);
	*pole = nullptr;

}

void Swiat::WstawiZabijOrganizm(Byt * do_zabicia, Byt * do_wstawienia)
{
	Pos pozycja1 = do_zabicia->Daj_Pozycje();
	Pos pozycja2 = do_wstawienia->Daj_Pozycje();

	Byt** pole = WezPole(pozycja1.X, pozycja1.Y);
	Byt** stare_pole = WezPole(pozycja2.X, pozycja2.Y);
	Byt* do_zabiciax = *pole;
	*pole = do_wstawienia;

	do_wstawienia->Set_Pozycje(pozycja1);

	lista.remove(do_zabicia);

	garbagelist.push_back(do_zabicia);
	*stare_pole = nullptr;


}


Byt** Swiat::WezPole(size_t x, size_t y)
{
	Byt** bytmp = &(tab[x][y]);

	return bytmp;
}


Pos Swiat::ZnajdzNajblizszy(Pos pozyciapocz, char zwierzekon)
{
	int mindlugosc = 9999999;
	Pos min_pos;
	Pos tmp_pos;
	int postmp = 0;
	for (auto &v : tab)
	{
		for (auto &j : v)
		{
			if (j == nullptr)
			{
				//....
			}
			else
			{
				if (j->Rysowanie() == zwierzekon)
				{
					tmp_pos = j->Daj_Pozycje();
					int raz = tmp_pos.X;
					int dwa = pozyciapocz.Y;
					int trzy = tmp_pos.Y;
					int cztery = pozyciapocz.X;
					postmp = abs(raz-dwa) + abs(trzy-cztery);
					if (postmp <= mindlugosc)
					{
						mindlugosc = postmp;
						min_pos = tmp_pos;
					}
				}
			}

		}

	}
	if (mindlugosc < 9999999)
	{
		return min_pos;
	}
	else
		throw "Nie ma!";
}
