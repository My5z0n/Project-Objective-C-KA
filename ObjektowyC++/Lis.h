#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(Pos tmp, Swiat * jakiswiat);
	~Lis();
	Lis*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

