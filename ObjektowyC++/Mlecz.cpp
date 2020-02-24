#include "Mlecz.h"




Mlecz::Mlecz(Pos tmp, Swiat * jakiswiat) : Roslina(tmp, 0, 1, 40, jakiswiat, "Mlecz")
{

}

Mlecz::~Mlecz()
{

}

Mlecz * Mlecz::StworzDziecko(Pos pozycjay)
{
	Mlecz* mlecz = new Mlecz(pozycjay, referencja);
	return mlecz;
}

void Mlecz::Akcja()
{
	Roslina::Akcja();
	Roslina::Akcja();
	Roslina::Akcja();
}

char Mlecz::Rysowanie()
{
	return '^';
}
