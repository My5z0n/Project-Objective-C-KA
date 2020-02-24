#include "CyberOwca.h"



CyberOwca::CyberOwca(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 11, 4, 1, jakiswiat, "Cyber Owca")
{
}

CyberOwca::~CyberOwca()
{
}

CyberOwca * CyberOwca::StworzDziecko(Pos pozycjay)
{
	CyberOwca* owca = new CyberOwca(pozycjay, referencja);
	return owca;
}

char CyberOwca::Rysowanie()
{
	return 'C';
}

void CyberOwca::Akcja()
{
	Pos cel;
	try
	{
		cel = referencja->ZnajdzNajblizszy(pozycja, '$');

		if (cel.X > pozycja.X)
		{
			nastepnykier = DOWN;
		}
		else if (cel.X < pozycja.X)
		{
			nastepnykier = UP;
		}
		else if (cel.Y < pozycja.Y)
		{
			nastepnykier = LEFT;
		}
		else if (cel.Y > pozycja.Y)
		{
			nastepnykier = RIGHT;
		}
		else
		{
			nastepnykier = NONE;
		}
		Zwierze::Akcja();
	}
	catch (const char* wyjatek)
	{
		nastepnykier = NONE;
		Zwierze::Akcja();
	}

}
