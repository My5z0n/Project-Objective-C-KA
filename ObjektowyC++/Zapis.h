#pragma once
#include <iostream> 
#include <fstream> 
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "CyberOwca.h"
#include "Czlowiek.h"

using namespace std;
class Zapis
{
public:
	Zapis();
	void Zapisz(Swiat** referencja);
	void Odczytaj(Swiat** referencja, Opowiadacz* opowiadacz1);
	~Zapis();
};

