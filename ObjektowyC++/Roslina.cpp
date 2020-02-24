#include "Roslina.h"
#include<string>

void Roslina::RuszSie(Pos  pozycjax)
{
	referencja->WstawOrganizm(pozycjax, this);
	referencja->UsunOrganizm(pozycja);
	pozycja = pozycjax;
}

Roslina::Roslina(Pos tmp, int sila_tmp, int wiek_tmp, int szansa_rozsiania_tmp, Swiat * jakiswiat, std::string nazwa_tmp) : szansa_rozsiania(szansa_rozsiania_tmp), Organizm(tmp, sila_tmp, wiek_tmp, 0, ROSLINA, jakiswiat, nazwa_tmp)
{

}

void Roslina::Akcja()
{

	Pos dana;
	Byt** jakisbyt;
	if (nastepnykier == NONE)
		dana = PoczatekAkcji();
	else
		dana = PoczatekAkcji(nastepnykier);

	if (System_Decyzyjny(CZY_RUSZYC, dana))
	{
		jakisbyt = referencja->WezPole(dana.X, dana.Y);
		if ((*jakisbyt) != this)
		{

			if (*jakisbyt == nullptr)
			{

				Rozmnoz(dana);
			}
			else
			{
				//....
			}
		}

	}
}

void Roslina::Kolizja(Pos pozycjax)
{
	Byt** wywolany_z_kolizji = referencja->WezPole(pozycjax.X, pozycjax.Y);

	if (this->Rysowanie() == (*wywolany_z_kolizji)->Rysowanie())
	{
		//......

	}
	else
	{
		if (System_Decyzyjny(CZY_WALCZYC, pozycjax))
		{
			Walcz(pozycjax);
		}
	}
}

void Roslina::Rozmnoz(Pos pozycjax)
{
	bool warunek1 = 1;
	bool warunek2 = 1;
	bool warunek3 = 1;
	bool warunek4 = 1;

	Kierunki kier = wybierzkierunek();
	Pos pole;
	while (warunek1 || warunek2 || warunek3 || warunek4)
	{
		kier = wybierzkierunek();
		pole = WybiezPole(referencja, pozycja, kier);
		Byt** bytref = referencja->WezPole(pole.X, pole.Y);
		if ((pole.X == pozycja.X&&pole.Y == pozycja.Y) || (*bytref) != nullptr)
		{
			switch (kier)
			{
			case UP:
				warunek1 = false;
				break;
			case DOWN:
				warunek2 = false;
				break;
			case LEFT:
				warunek3 = false;
				break;
			case RIGHT:
				warunek4 = false;
				break;
			default:
				break;
			}
		}
		else
		{
			referencja->WstawOrganizm(pole, StworzDziecko(pole));
			break;
		}
	}
}

void Roslina::Walcz(Pos pozycjax)
{
	if (System_Decyzyjny(CZY_PRZEPROWADZIC_WALKE, pozycjax))
	{
		Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int wrogasila = (*wrogibyt)->GetSila();
		Pos oldpos = pozycja;
		if (wrogasila > sila)
		{
			referencja->WstawiZabijOrganizm(this, *wrogibyt);
		}
		else if (wrogasila == sila)
		{
			referencja->WstawiZabijOrganizm(this, *wrogibyt);
		}
		else
		{
			Pos pozycjawroga = (*wrogibyt)->Daj_Pozycje();
			referencja->ZabijOrganizm(pozycjawroga);
		}
	}
}

bool Roslina::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_RUSZYC)
		return szansa_rozsiania > rand() % 100 + 1;
	else
		return true;
}
