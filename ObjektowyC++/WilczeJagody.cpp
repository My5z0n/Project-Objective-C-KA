#include "WilczeJagody.h"





WilczeJagody::WilczeJagody(Pos tmp, Swiat * jakiswiat) : Roslina(tmp, 99, 1, 25, jakiswiat, "Wilcze Jagody")
{

}

WilczeJagody::~WilczeJagody()
{

}

WilczeJagody * WilczeJagody::StworzDziecko(Pos pozycjay)
{
	WilczeJagody* wilczeJagody = new WilczeJagody(pozycjay, referencja);
	return wilczeJagody;
}

char WilczeJagody::Rysowanie()
{
	return '#';
}

bool WilczeJagody::System_Decyzyjny(Decyzje pytanie, Pos pozycjax)
{
	if (pytanie == CZY_PRZEPROWADZIC_WALKE)
	{

		Byt** wrogibyt = referencja->WezPole(pozycjax.X, pozycjax.Y);
		int wrogasila = (*wrogibyt)->GetSila();
		Pos oldpos = pozycja;


		std::string tmp = (*wrogibyt)->GetNazwa();
		referencja->DodajZdarzenie(nazwaorganizmu + " Zostala zjedzona przez " + tmp + " w wyniku czego umarl na smierc");


		referencja->ZabijOrganizm(pozycjax);
		referencja->ZabijOrganizm(pozycja);
		return false;



	}
	else
		return Roslina::System_Decyzyjny(pytanie, pozycjax);
}




