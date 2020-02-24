#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(Pos tmp, Swiat * jakiswiat);
	~Mlecz();
	Mlecz*  StworzDziecko(Pos pozycjay) override;
	void Akcja() override;
	char Rysowanie() override;
};

