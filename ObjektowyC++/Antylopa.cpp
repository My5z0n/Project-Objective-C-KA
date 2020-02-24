#include "Antylopa.h"





Antylopa::Antylopa(Pos tmp, Swiat * jakiswiat) : ruch_antylopy(0), Zwierze(tmp, 4, 4, 1, jakiswiat, "Antylopa")
{
}

Antylopa::~Antylopa()
{

}

void Antylopa::Akcja()
{
	Zwierze::Akcja();

}

Antylopa * Antylopa::StworzDziecko(Pos pozycjay)
{

	Antylopa* antylopa = new Antylopa(pozycjay, referencja);
	return antylopa;
}

char Antylopa::Rysowanie()
{
	return 'A';
}

bool Antylopa::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	bool Czy_ucieczka;
	if (pytanie == CZY_WYKONAC_RUCH)
	{
		if (ruch_antylopy == 0)
		{
			RuszSie(pozycjax);
			ruch_antylopy++;
			Antylopa::Akcja();

			return false;
		}
		if (ruch_antylopy == 1)
		{
			ruch_antylopy = 0;
			return true;
		}

	}
	else if (pytanie == CZY_PRZEPROWADZIC_WALKE)
	{
		if (50 < rand() % 100 + 1)
		{
			Czy_ucieczka = Ucieczka(pozycjax);
			return Czy_ucieczka;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}

}

bool Antylopa::Ucieczka(Pos pozycjax)
{
	Pos poletmp;
	poletmp = pozycja;
	Pos pole;
	Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
	int wrogasila = (*wrogibyt)->GetSila();
	Pos oldpos = pozycja;
	try
	{
		std::string tmp = (*wrogibyt)->GetNazwa();
		referencja->DodajZdarzenie("Antylopa uciekla przed walka z " + tmp);
		pole = Daj_wolne_pole_obok(pozycja);
		referencja->WstawOrganizm(pole, this);
		Set_Pozycje(pole);
		referencja->WstawOrganizm(poletmp, *wrogibyt);
		(*wrogibyt)->Set_Pozycje(poletmp);
		referencja->UsunOrganizm(pozycjax);

		return false;
	}
	catch (const char* wyjatek)
	{
		return true;
	}

}
