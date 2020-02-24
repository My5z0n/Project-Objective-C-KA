#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(Pos tmp, Swiat * jakiswiat);
	~Guarana();
	Guarana*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

