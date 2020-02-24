#pragma once
#include "Zwierze.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(Pos tmp, Swiat * jakiswiat);
	~Wilk();
	Wilk*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
};

