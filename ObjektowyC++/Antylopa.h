#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
private:
	int ruch_antylopy;
public:
	Antylopa(Pos tmp, Swiat * jakiswiat);
	~Antylopa();
	void Akcja() override;
	Antylopa*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
	bool Ucieczka(Pos pozycjax);

};

