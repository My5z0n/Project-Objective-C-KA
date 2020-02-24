#include "Czlowiek.h"







Czlowiek::Czlowiek(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 5, 4, 1, jakiswiat, "Czlowiek"), czas_umiejetnosc(0), buff(0), czy_umiejetnosc(0)
{
}

Czlowiek::~Czlowiek()
{
}

Czlowiek * Czlowiek::StworzDziecko(Pos pozycjay)
{
	Czlowiek* czlowiek = new Czlowiek(pozycjay, referencja);
	return czlowiek;
}

char Czlowiek::Rysowanie()
{
	return '@';
}

void Czlowiek::Akcja()
{

	if (buff != 0)
	{
		buff--;
	}
	if (czas_umiejetnosc != 0)
	{
		czas_umiejetnosc--;
	}
	if (czas_umiejetnosc == 0)
	{
		czy_umiejetnosc = false;
	}
	Zwierze::Akcja();

}

void Czlowiek::SetUmiejetnosc(Specjalna_Akcja akcja)
{
	if (akcja == TARCZA)
	{
		if (buff == 0)
		{
			czy_umiejetnosc = true;
			buff = 10;
			czas_umiejetnosc = 5;
		}
		else
		{
			throw "Nie mozna jeszcze aktywowac!";
		}
	}
	else
	{
		//Nic...
	}
}

bool Czlowiek::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_PRZEPROWADZIC_WALKE && czy_umiejetnosc)
	{

		Byt** jakisbyt;
		jakisbyt = referencja->WezPole(pozycjax.X, pozycjax.Y);

		Pos pole;
		try
		{
			std::string tmp = (*jakisbyt)->GetNazwa();
			referencja->DodajZdarzenie("Czlowiek dzieki aktywnej umiejetnosci odbil atak " + tmp);

			pole = Daj_wolne_pole_obok(pozycja);
			(*jakisbyt)->Set_Pozycje(pole);
			referencja->WstawOrganizm(pole, (*jakisbyt));
			referencja->UsunOrganizm(pozycjax);


		}
		catch (const char* wyjatek)
		{
			//Nie udalo sie przesunac na inne pole wiec niech zostanie na tym na ktorym jest...
		}


		return false;

	}
	else
		return Zwierze::System_Decyzyjny(pytanie, pozycjax);
}


