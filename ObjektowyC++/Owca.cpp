#include "Owca.h"



Owca::Owca(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 4, 4, 1, jakiswiat, "Owca")
{
}

Owca::~Owca()
{
}

Owca * Owca::StworzDziecko(Pos pozycjay)
{
	Owca* owca = new Owca(pozycjay, referencja);
	return owca;
}

char Owca::Rysowanie()
{
	return 'O';
}
