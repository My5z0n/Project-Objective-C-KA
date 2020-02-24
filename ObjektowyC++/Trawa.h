#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(Pos tmp, Swiat * jakiswiat);
	~Trawa();
	Trawa*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
};

