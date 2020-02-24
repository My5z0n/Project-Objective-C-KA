#include "Trawa.h"





Trawa::Trawa(Pos tmp, Swiat * jakiswiat) : Roslina(tmp, 0, 1, 75, jakiswiat, "Trawa")
{

}

Trawa::~Trawa()
{

}

Trawa * Trawa::StworzDziecko(Pos pozycjay)
{
	Trawa* trawa = new Trawa(pozycjay, referencja);
	return trawa;
}

char Trawa::Rysowanie()
{
	return '!';
}
