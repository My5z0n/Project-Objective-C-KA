#pragma once
#include "Roslina.h"
class WilczeJagody :
	public Roslina
{
public:
	WilczeJagody(Pos tmp, Swiat * jakiswiat);
	~WilczeJagody();
	WilczeJagody*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

