#pragma once
#include "Roslina.h"
class BarszczSonsowskiego :
	public Roslina
{
public:
	void Zabij_wokol();
	BarszczSonsowskiego(Pos tmp, Swiat * jakiswiat);
	~BarszczSonsowskiego();
	BarszczSonsowskiego*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	void Akcja() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

