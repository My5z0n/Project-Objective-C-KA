#include "Guarana.h"





Guarana::Guarana(Pos tmp, Swiat * jakiswiat) : Roslina(tmp, 0, 1, 25, jakiswiat, "Guarana")
{

}

Guarana::~Guarana()
{

}

Guarana * Guarana::StworzDziecko(Pos pozycjay)
{
	Guarana* guarana = new Guarana(pozycjay, referencja);
	return guarana;
}

char Guarana::Rysowanie()
{
	return '%';
}

bool Guarana::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_PRZEPROWADZIC_WALKE)
	{


		Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int wrogasila = (*wrogibyt)->GetSila();
		Pos oldpos = pozycja;
		if (wrogasila >= sila)
		{
			std::string tmp = (*wrogibyt)->GetNazwa();
			referencja->DodajZdarzenie(nazwaorganizmu + " Zostala zjedzona przez " + tmp + " i zwiekszyl dzieki temu swoja sile o +3");
			(*wrogibyt)->SetSila((*wrogibyt)->GetSila() + 3);
		}
		return true;

	}
	else
		return Roslina::System_Decyzyjny(pytanie, pozycjax);
}




