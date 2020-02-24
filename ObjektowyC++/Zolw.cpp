#include "Zolw.h"
#include <iostream>




Zolw::Zolw(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 2, 1, 1, jakiswiat, "Zolw")
{
	//int sila_tmp, int inicjat, int wiek_tmp,
}

Zolw::~Zolw()
{

}

Zolw * Zolw::StworzDziecko(Pos pozycjay)
{

	Zolw* zolw = new Zolw(pozycjay, referencja);
	return zolw;
}

char Zolw::Rysowanie()
{
	return 'Z';
}

bool Zolw::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_PRZEPROWADZIC_WALKE)
	{
		Byt** jakisbyt;
		jakisbyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int silawroga;

		if ((*jakisbyt) != this)
		{

			if (*jakisbyt == nullptr)
			{
				//Cos Dziwnego
				throw "Bad arguments!";
			}
			else
			{
				silawroga = (*jakisbyt)->GetSila();
				if (silawroga < 5)
				{
					std::string xD = (*jakisbyt)->GetNazwa();
					referencja->DodajZdarzenie("Zolw odbil atak " + xD);

					return false;

					//Nie walczyæ i nic nie robiæ wiêcej... 
				}
				else
					return true;
				//Przeprowadziæ zwyk³¹ walkê
			}
		}
		return true;

	}
	else
		return true;
}
