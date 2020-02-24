#include "Organizm.h"


Pos Organizm::WybiezPole(Swiat *ref, Pos poz, Kierunki kierunek)
{
	size_t x = poz.X;
	size_t y = poz.Y;
	size_t roz = ref->Getrozmiar();
	size_t roz2 = ref->Getrozmiar2();
	size_t newx = x;
	size_t newy = y;
	switch (kierunek)
	{
	case UP:
		if (newx > 0)
			newx--;
		break;
	case DOWN:
		newx++; break;
	case RIGHT:
		newy++; break;
	case LEFT:
		if (newy > 0)
			newy--; break;
	default:
		break;
	}

	if (newx < 0)
	{
		newx = 0;
	}
	else if (newx >= roz)
	{
		newx--;
	}
	else if (newy < 0)
	{
		newx = 0;

	}
	else if (newy >= roz2)
	{
		newy--;
	}

	return  Pos{ newx, newy };
}

Organizm::Organizm(Pos tmp, int sila_tmp, int wiek_tmp, int inicjat, Typ typorganizmux, Swiat * jakiswiat, std::string nazwa_tmp) : referencja(jakiswiat), Byt(wiek_tmp, sila_tmp, inicjat, tmp, typorganizmux, nazwa_tmp)
{

}

Pos Organizm::PoczatekAkcji()
{
	Kierunki kierunek;
	Byt** jakisbyt;
	Pos pozxx;
	kierunek = wybierzkierunek();
	pozxx = WybiezPole(referencja, pozycja, kierunek);
	jakisbyt = referencja->WezPole(pozxx.X, pozxx.Y);
	return(pozxx);
}

Pos Organizm::PoczatekAkcji(Kierunki jakiskierunek)
{

	Byt** jakisbyt;
	Pos pozxx;
	pozxx = WybiezPole(referencja, pozycja, jakiskierunek);
	jakisbyt = referencja->WezPole(pozxx.X, pozxx.Y);
	return(pozxx);
}

bool Organizm::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	return true;
}








Kierunki Organizm::wybierzkierunek()
{
	int random = rand() % 4;
	Kierunki kierunek = (Kierunki)random;
	return kierunek;
}
