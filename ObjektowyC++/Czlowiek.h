#pragma once
#include "Zwierze.h"
class Czlowiek :
	public Zwierze
{
	friend class Zapis;
private:
	bool czy_umiejetnosc;
	int czas_umiejetnosc;
	int buff;
public:

	Czlowiek(Pos tmp, Swiat * jakiswiat);
	~Czlowiek();
	Czlowiek*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	void Akcja() override;
	void SetUmiejetnosc(Specjalna_Akcja akcja) override;
	bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;
};

