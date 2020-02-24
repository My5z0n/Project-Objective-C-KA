#include "BarszczSosnowskiego.h"




void BarszczSonsowskiego::Zabij_wokol()
{
	Byt** jakisbyt;
	Pos pozxx;
	for (int i = 0; i < 4; i++)
	{
		pozxx = WybiezPole(referencja, pozycja, (Kierunki)i);
		jakisbyt = referencja->WezPole(pozxx.X, pozxx.Y);
		if ((*jakisbyt) != this && (*jakisbyt) != nullptr && (*jakisbyt)->GetTyp() != ROSLINA && (*jakisbyt)->Rysowanie() != 'C')
		{
			std::string tmp = (*jakisbyt)->GetNazwa();
			referencja->DodajZdarzenie("POTEZNY Barszcz Sosnowskiego zabil " + tmp + " bo zbytnio sie do niego zblizyl");
			referencja->ZabijOrganizm(pozxx);
		}

	}
}

BarszczSonsowskiego::BarszczSonsowskiego(Pos tmp, Swiat * jakiswiat) : Roslina(tmp, 10, 1, 25, jakiswiat, "Barszcz Sonsowskiego")
{

}

BarszczSonsowskiego::~BarszczSonsowskiego()
{

}

BarszczSonsowskiego * BarszczSonsowskiego::StworzDziecko(Pos pozycjay)
{
	BarszczSonsowskiego* barszczSonsowskiego = new BarszczSonsowskiego(pozycjay, referencja);
	return barszczSonsowskiego;
}

char BarszczSonsowskiego::Rysowanie()
{
	return '$';
}

void BarszczSonsowskiego::Akcja()
{
	Zabij_wokol();
	Roslina::Akcja();
}

bool BarszczSonsowskiego::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_PRZEPROWADZIC_WALKE)
	{


		Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int wrogasila = (*wrogibyt)->GetSila();
		Pos oldpos = pozycja;

		if ((*wrogibyt)->Rysowanie() != 'C')
		{
			std::string tmp = (*wrogibyt)->GetNazwa();
			referencja->DodajZdarzenie("POTEZNY Barszcz Sosnowskiego zabil " + tmp + " w bezposrednim starciu");

			referencja->ZabijOrganizm(pozycjax);
			referencja->ZabijOrganizm(pozycja);
			return false;
		}
		else
		{
			std::string tmp = (*wrogibyt)->GetNazwa();
			referencja->DodajZdarzenie("POTEZNY Barszcz Sosnowskiego zostal zjedzony przez jeszcze POTEZNIEJSZA " + tmp);
			referencja->WstawiZabijOrganizm(this, *wrogibyt);
			return false;
		}



	}
	else
		return Roslina::System_Decyzyjny(pytanie, pozycjax);
}
