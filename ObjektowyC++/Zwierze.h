#pragma once
#include "Organizm.h"
class Zwierze :
	public Organizm
{
	friend class Zapis;
protected:
	void RuszSie(Pos pozx);
	Pos Daj_wolne_pole_obok(Pos pozycjax);
public:
	Zwierze(Pos tmp, int sila_tmp, int inicjat, int wiek_tmp, Swiat * jakiswiat, std::string nazwa_tmp);
	virtual void Akcja() override;
	virtual void Kolizja(Pos pozycjax) override;
	virtual void Rozmnoz(Pos pozycjax) override;
	virtual void Walcz(Pos pozycjax) override;

};

