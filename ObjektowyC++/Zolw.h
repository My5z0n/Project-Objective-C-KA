#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(Pos tmp, Swiat * jakiswiat);
	~Zolw();
	Zolw*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

