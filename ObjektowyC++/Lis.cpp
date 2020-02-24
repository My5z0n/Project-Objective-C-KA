#include "Lis.h"





Lis::Lis(Pos tmp, Swiat * jakiswiat) : Zwierze(tmp, 3, 7, 1, jakiswiat, "Lis")
{

}

Lis::~Lis()
{

}

Lis * Lis::StworzDziecko(Pos pozycjay)
{

	Lis* lis = new Lis(pozycjay, referencja);
	return lis;
}

char Lis::Rysowanie()
{
	return 'L';
}

bool Lis::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_RUSZYC)
	{
		Byt** jakisbyt;
		jakisbyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int silawroga;

		if ((*jakisbyt) != this)
		{

			if (*jakisbyt == nullptr)
			{

				return true;
			}
			else
			{
				silawroga = (*jakisbyt)->GetSila();
				if (sila < silawroga)
					return false;
				else
					return true;
			}
		}
		return true;

	}
	else
		return true;
}
