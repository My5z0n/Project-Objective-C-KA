#include "Opowiadacz.h"



Opowiadacz::Opowiadacz()
{
}

void Opowiadacz::Czysc()
{
	dane.clear();
}

void Opowiadacz::Dodaj(std::string tekst)
{
	dane.push_back(tekst);
}

bool Opowiadacz::Opowiedz()
{
	bool test = 0;

	std::cout << "----Zdarzenia z tury----" << std::endl;
	for (auto x : dane)
	{
		test = 1;
		std::cout << x << std::endl;
	}
	std::cout << "-----Koniec Zdarzen-----" << std::endl;
	return test;
}


Opowiadacz::~Opowiadacz()
{
}
