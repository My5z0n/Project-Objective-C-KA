#include "Wilk.h"





Wilk::Wilk(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 9, 5, 1, jakiswiat, "Wilk")
{

}

Wilk::~Wilk()
{
}

Wilk * Wilk::StworzDziecko(Pos pozycjay)
{

	Wilk* nowywilk = new Wilk(pozycjay, referencja);
	return nowywilk;
}

char Wilk::Rysowanie()
{
	return 'W';
}
