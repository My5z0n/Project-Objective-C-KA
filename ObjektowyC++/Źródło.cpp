#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <vector>
#include <time.h>
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
#include "Zapis.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


using namespace std;



int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	SetConsoleTitle(TEXT("LAKA"));
	bool czy_zyje_czlowiek = 1;
	char input;
	Opowiadacz opowiadacz1;
	Swiat* swiat1;
	Zapis zapis1;
	swiat1 = new Swiat{ 25,30,&opowiadacz1 };
	
	
	//Przykladowe zwierzatka do demonstacji
	Zwierze* wilk1;
	Zwierze* czlowiek;
	Zwierze* wilk2;
	Zwierze* owca1;
	Zwierze* owca2;
	Zwierze* lis1;
	Zwierze* lis2;
	Zwierze* zolw1;
	Zwierze* zolw2;
	Zwierze* antylopa1;
	Zwierze* antylopa2;
	Zwierze* cyberowca;
	Pos pozycja{ 19,4 };
	Roslina* trawka;
	Roslina* mlecz;
	Roslina* guarana;
	Roslina* wilczejagody;
	Roslina* barszcz;


	trawka = new Trawa(pozycja, swiat1);
	(swiat1)->WstawOrganizm(trawka->Daj_Pozycje(), trawka);

	pozycja = { 18, 18 };


	pozycja = { 15, 29 };
	trawka = new Trawa(pozycja, swiat1);
	(swiat1)->WstawOrganizm(trawka->Daj_Pozycje(), trawka);

	pozycja = { 18, 18 };
	barszcz = new BarszczSonsowskiego(pozycja, swiat1);
	(swiat1)->WstawOrganizm(barszcz->Daj_Pozycje(), barszcz);

	pozycja = { 18, 24 };
	mlecz = new Mlecz(pozycja, swiat1);
	(swiat1)->WstawOrganizm(mlecz->Daj_Pozycje(), mlecz);

	pozycja = { 5, 5 };
	guarana = new Guarana(pozycja, swiat1);
	(swiat1)->WstawOrganizm(guarana->Daj_Pozycje(), guarana);

	pozycja = { 5, 20 };
	wilczejagody = new WilczeJagody(pozycja, swiat1);
	(swiat1)->WstawOrganizm(wilczejagody->Daj_Pozycje(), wilczejagody);




	//W tym miescu dodajemy czlowieka
	pozycja = { 24, 15 };
	czlowiek = new Czlowiek(pozycja, swiat1);
	(swiat1)->WstawOrganizm(czlowiek->Daj_Pozycje(), czlowiek);

	pozycja = { 0, 24 };
	cyberowca = new CyberOwca(pozycja, swiat1);
	(swiat1)->WstawOrganizm(cyberowca->Daj_Pozycje(), cyberowca);


	pozycja = { 0, 0 };
	antylopa1 = new Antylopa(pozycja, swiat1);
	(swiat1)->WstawOrganizm(antylopa1->Daj_Pozycje(), antylopa1);
	pozycja = { 7, 4 };
	antylopa2 = new Antylopa(pozycja, swiat1);
	(swiat1)->WstawOrganizm(antylopa2->Daj_Pozycje(), antylopa2);

	pozycja = { 0, 17 };
	zolw1 = new Zolw(pozycja, swiat1);
	(swiat1)->WstawOrganizm(zolw1->Daj_Pozycje(), zolw1);
	pozycja = { 1, 22 };
	zolw2 = new Zolw(pozycja, swiat1);
	(swiat1)->WstawOrganizm(zolw2->Daj_Pozycje(), zolw2);

	pozycja = { 6,14 };
	wilk1 = new Wilk(pozycja, swiat1);
	(swiat1)->WstawOrganizm(wilk1->Daj_Pozycje(), wilk1);
	pozycja = { 12,14 };
	wilk2 = new Wilk(pozycja, swiat1);
	(swiat1)->WstawOrganizm(wilk2->Daj_Pozycje(), wilk2);


	pozycja = { 11,19 };
	lis1 = new Lis(pozycja, swiat1);
	(swiat1)->WstawOrganizm(lis1->Daj_Pozycje(), lis1);
	pozycja = { 12,5 };
	lis2 = new Lis(pozycja, swiat1);
	(swiat1)->WstawOrganizm(lis2->Daj_Pozycje(), lis2);
	pozycja = { 12,25 };
	lis2 = new Lis(pozycja, swiat1);
	(swiat1)->WstawOrganizm(lis2->Daj_Pozycje(), lis2);

	pozycja = { 23,3 };
	owca1 = new Owca(pozycja, swiat1);
	(swiat1)->WstawOrganizm(owca1->Daj_Pozycje(), owca1);
	pozycja = { 21,8 };
	owca2 = new Owca(pozycja, swiat1);
	(swiat1)->WstawOrganizm(owca2->Daj_Pozycje(), owca2);
	pozycja = { 21,28 };
	owca2 = new Owca(pozycja, swiat1);
	(swiat1)->WstawOrganizm(owca2->Daj_Pozycje(), owca2);

	bool wybierz = 0;
	opowiadacz1.Czysc();
	while(true)
	{


		system("cls");
		
		swiat1->RysujSwiat();
		Sleep(50);


		if (czy_zyje_czlowiek)
		{
			wybierz = 0;
			while (!wybierz&&czy_zyje_czlowiek)
			{
				cout << "Wybierz ruch czlowieka:" << endl;


				input = _getch();
				if (input == 'f')
				{
					try
					{
						swiat1->AktywujUmiejetnosc(TARCZA);
						cout << "Aktywowanu umiejetnosc: TARCZA" << endl;

					}
					catch (const char* wyjatek)
					{
						cout << wyjatek << endl;
					}

				}
				else if (input == 's')
				{

					try
					{
						zapis1.Zapisz(&swiat1);
					}
					catch (const char* wyjatek)
					{
						cout << wyjatek << endl;
						system("pause");
					}

				}
				else if (input == 'l')
				{
					try
					{
						zapis1.Odczytaj(&swiat1, &opowiadacz1);
					}
					catch (const char* xD)
					{

						system("cls");
						swiat1->RysujSwiat();
						Sleep(50);
						cout << xD << endl;
						system("pause");
					}

				}
				else if (input == 'à')
				{
					try
					{
						switch ((input = _getch())) {
						case KEY_UP:
							swiat1->KazRuszycCzlowiekowi(UP);
							wybierz = 1;
							break;
						case KEY_DOWN:
							swiat1->KazRuszycCzlowiekowi(DOWN);
							wybierz = 1;
							break;
						case KEY_LEFT:
							swiat1->KazRuszycCzlowiekowi(LEFT);
							wybierz = 1;
							break;
						case KEY_RIGHT:
							swiat1->KazRuszycCzlowiekowi(RIGHT);
							wybierz = 1;
							break;
						default:
							swiat1->KazRuszycCzlowiekowi(NONE);
							wybierz = 1;
							break;
						}
					}
					catch (const char* wyjatek)
					{
						czy_zyje_czlowiek = 0;
					}
				}



			}


		}
		opowiadacz1.Czysc();
		swiat1->WykonajTure();
		if (opowiadacz1.Opowiedz())
		{
			system("pause");
		}
	}
}
