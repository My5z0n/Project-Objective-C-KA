#pragma once
#include "Zwierze.h"
class CyberOwca :
	public Zwierze
{
public:
	CyberOwca(Pos tmp, Swiat * jakiswiat);
	~CyberOwca();
	CyberOwca*  StworzDziecko(Pos pozycjay) override;
	char Rysowanie() override;
	void Akcja() override;
};

