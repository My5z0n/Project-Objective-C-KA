#include "Zwierze.h"
#include<string>

//Ruch zwierzecia
void Zwierze::RuszSie(Pos  pozycjax)
{
	referencja->WstawOrganizm(pozycjax, this);
	referencja->UsunOrganizm(pozycja);
	pozycja = pozycjax;
}

//Konstruktor Zwierzecia
Zwierze::Zwierze(Pos tmp, int sila_tmp, int inicjat, int wiek_tmp, Swiat * jakiswiat, std::string nazwa_tmp) : Organizm(tmp, sila_tmp, wiek_tmp, inicjat, ZWIERZE, jakiswiat, nazwa_tmp)
{
}

void Zwierze::Akcja()
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

				if (System_Decyzyjny(CZY_WYKONAC_RUCH, dana))
				{
					RuszSie(dana);
				}

			}
			else
			{
				(*jakisbyt)->Kolizja(this->pozycja);
			}
		}

	}
}

void Zwierze::Kolizja(Pos pozycjaxx)
{
	Byt** wywolany_z_kolizji = referencja->WezPole(pozycjaxx.X, pozycjaxx.Y);

	if (this->Rysowanie() == (*wywolany_z_kolizji)->Rysowanie())
	{

		if (System_Decyzyjny(CZY_ROZMNOZYC, pozycjaxx))
		{
			Rozmnoz(pozycjaxx);
		}
	}
	else
	{
		if (System_Decyzyjny(CZY_WALCZYC, pozycjaxx))
		{
			Walcz(pozycjaxx);
		}
	}
}

Pos Zwierze::Daj_wolne_pole_obok(Pos pozycjax)
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
		if ((pole.X == pozycjax.X&&pole.Y == pozycjax.Y) || (*bytref) != nullptr)
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
			return pole;
			break;
		}
	}
	throw "Nie istnieje!";
}

void Zwierze::Rozmnoz(Pos pozycjax)
{
	Pos pole;
	try
	{

		pole = Daj_wolne_pole_obok(pozycjax);
		referencja->WstawOrganizm(pole, StworzDziecko(pole));
		referencja->DodajZdarzenie(nazwaorganizmu + " rozmnozyl sie");
	}
	catch (const char* wyjatek)
	{
		//Nie udalo sie rozmnozyc wiec nic nie rob dalej...
	}
}

void Zwierze::Walcz(Pos pozycjax)
{
	if (System_Decyzyjny(CZY_PRZEPROWADZIC_WALKE, pozycjax))
	{
		Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int wrogasila = (*wrogibyt)->GetSila();
		Pos oldpos = pozycja;
		if (wrogasila > sila)
		{


			if (typorganizmu != ROSLINA)
			{
				std::string xd = (*wrogibyt)->GetNazwa();
				std::string xdd = nazwaorganizmu;
				std::string xddd = xd + " Zaatakowal i Zjadl " + xdd;

				referencja->DodajZdarzenie(xddd);
			}
			referencja->WstawiZabijOrganizm(this, *wrogibyt);


			//Zabij sie i wstaw inny organizm
		}
		else if (wrogasila == sila)
		{


			if (typorganizmu != ROSLINA)
			{
				std::string xd = (*wrogibyt)->GetNazwa();
				std::string xdd = nazwaorganizmu;
				std::string xddd = xd + " Zaatakowal i Zjadl " + xdd;

				referencja->DodajZdarzenie(xddd);
			}
			referencja->WstawiZabijOrganizm(this, *wrogibyt);

		}
		else
		{

			std::string xd = (*wrogibyt)->GetNazwa();
			std::string xdd = nazwaorganizmu;
			std::string xddd = xd + " Zaatakowal " + xdd + " i zgiol";
			referencja->DodajZdarzenie(xddd);

			Pos pozycjawroga = (*wrogibyt)->Daj_Pozycje();
			referencja->ZabijOrganizm(pozycjawroga);

		}
	}
}
