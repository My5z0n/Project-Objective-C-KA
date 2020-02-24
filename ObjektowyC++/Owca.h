#pragma once
#include "Zwierze.h"
class Owca :
	public Zwierze
{
public:
	Owca(Pos tmp, Swiat * jakiswiat);
	~Owca();
	Owca*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
};

