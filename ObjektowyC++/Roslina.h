#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
	friend class Zapis;
private:
protected:
	void RuszSie(Pos pozx);
	int szansa_rozsiania;
public:
	Roslina(Pos tmp, int sila_tmp, int wiek_tmp, int szansa_rozsiania_tmp, Swiat * jakiswiat, std::string nazwa_tmp);
	virtual void Akcja() override;
	virtual void Kolizja(Pos pozycjax) override;
	virtual void Rozmnoz(Pos pozycjax) override;
	virtual void Walcz(Pos pozycjax) override;
	virtual bool System_Decyzyjny(Decyzje pytanie, Pos pozycjax) override;

};

