#define _CRT_SECURE_NO_WARNINGS
#include "Zapis.h"


struct Saving
{
	int raz;
	Kierunki dwa;
	char trzy[25];
	Pos cztery;
	int piec;
	Typ szesc;
	int siedem;
};


Zapis::Zapis()
{
}



//Rêczna serializa
void Zapis::Zapisz(Swiat** referencja)
{

	fstream file_obj;


	file_obj.open("save", ios::binary | ios::out);

	vector <vector <Byt*>> tmp_vector;
	tmp_vector = (*referencja)->tab;

	size_t rozmar_tmp = (*referencja)->rozmiar;
	size_t rozmar_tmp2 = (*referencja)->rozmiar2;
	char xn = '\n';
	if (file_obj.good() == 1)
	{
		file_obj.write((char*)&rozmar_tmp, sizeof(size_t));
		file_obj.write(&xn, sizeof(xn));
		file_obj.write((char*)&rozmar_tmp2, sizeof(size_t));
		file_obj.write(&xn, sizeof(xn));
		string name;
		Pos tmp_pos{ 0,0 };
		Saving save_tmp;
		for (auto &v : tmp_vector)
		{
			for (auto &j : v)
			{
				if (j != nullptr)
				{
					name = j->GetNazwa();
					char nazwa[25];
					strcpy(nazwa, name.c_str());

					if (name == "Antylopa") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Antylopa* ymp;
						ymp = (Antylopa*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Barszcz Sonsowskiego") {
						nazwa[7] = '_';
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						BarszczSonsowskiego* ymp;
						ymp = (BarszczSonsowskiego*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Cyber Owca") {
						nazwa[5] = '_';
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						CyberOwca* ymp;
						ymp = (CyberOwca*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}

					//Czlowiek
					else if (name == "Czlowiek") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;

						Czlowiek* ymp;
						ymp = (Czlowiek*)j;
						bool x1 = ymp->czy_umiejetnosc;
						int x2 = ymp->czas_umiejetnosc;
						int x3 = ymp->buff;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write((char*)&(x1), sizeof(bool));
						file_obj.write((char*)&(x2), sizeof(int));
						file_obj.write((char*)&(x3), sizeof(int));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Guarana") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Guarana* ymp;
						ymp = (Guarana*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Lis") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Lis* ymp;
						ymp = (Lis*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Mlecz") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Mlecz* ymp;
						ymp = (Mlecz*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Owca") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Owca* ymp;
						ymp = (Owca*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Trawa") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Trawa* ymp;
						ymp = (Trawa*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Wilcze Jagody") {
						nazwa[6] = '_';
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						WilczeJagody* ymp;
						ymp = (WilczeJagody*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Wilk") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Wilk* ymp;
						ymp = (Wilk*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else if (name == "Zolw") {
						file_obj.write(nazwa, 25 * sizeof(char));
						file_obj.write(&xn, sizeof(xn));
						save_tmp.raz = j->inicjatywa;
						save_tmp.dwa = j->nastepnykier;
						strcpy(save_tmp.trzy, j->nazwaorganizmu.c_str());
						save_tmp.cztery = j->pozycja;
						save_tmp.piec = j->sila;
						save_tmp.szesc = j->typorganizmu;
						save_tmp.siedem = j->wiek;
						Zolw* ymp;
						ymp = (Zolw*)j;
						file_obj.write((char*)&(save_tmp), sizeof(Saving));
						file_obj.write(&xn, sizeof(xn));
					}
					else
					{
						throw "Blad logiczny podczas zapisu!";

					}
				}
				else
				{
					char xympDD[25] = "NULLPTR";
					file_obj.write(xympDD, 25 * sizeof(char));
					file_obj.write(&xn, sizeof(xn));

				}

			}
		}

		file_obj.close();

		if (file_obj.good() == 1)
		{
			throw "Zapis przebiegl pomyslnie!";
		}
	}
	else
	{
		throw "Blad podczas otwierania pliku!";
	}
}

void Zapis::Odczytaj(Swiat** referencja, Opowiadacz* opowiadacz1)
{

	fstream file_obj;

	file_obj.open("save", ios::binary | ios::in);

	if (file_obj.good() == true)
	{
		size_t rozmiar_tmp = 0;
		size_t rozmiar_tmp2 = 0;
		Saving* load;
		load = new Saving();
		file_obj.read((char*)&rozmiar_tmp, sizeof(size_t));
		char ympD = 'x';

		file_obj.read(&ympD, sizeof(char));
		file_obj.read((char*)&rozmiar_tmp2, sizeof(size_t));
		file_obj.read(&ympD, sizeof(char));

		Swiat* new_swiat;
		new_swiat = new Swiat(rozmiar_tmp, rozmiar_tmp2, opowiadacz1);

		string name;
		Pos tmp_pos{ 0,0 };

		int o = 0;

		char xympD[25];
		vector <vector <Byt*>>* tmp_vector = &(new_swiat->tab);
		for (auto &v : *tmp_vector)
		{
			for (auto &j : v)
			{


				Byt** tmp_byt = &j;
				xympD[0] = 'X';
				file_obj.read(xympD, 25 * sizeof(char));


				file_obj.read(&ympD, sizeof(char));

				if (file_obj.fail())
				{
					throw "Blad podczas wczytawania pliku!";
				}


				if (strcmp(xympD, "NULLPTR") == 0)
				{

					//
				}
				else if (strcmp(xympD, "Antylopa") == 0) {
					o++;


					Antylopa* newobject = new Antylopa(tmp_pos, new_swiat);




					file_obj.read((char*)load, sizeof(Saving));


					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;
					newobject->referencja = new_swiat;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
				}
				else if (strcmp(xympD, "Barszcz_Sonsowskiego") == 0) {
					o++;
					BarszczSonsowskiego* newobject = new BarszczSonsowskiego(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Cyber_Owca") == 0) {
					o++;
					CyberOwca* newobject = new CyberOwca(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				//Czlowiek
				else if (strcmp(xympD, "Czlowiek") == 0) {
					o++;
					Czlowiek* newobject = new Czlowiek(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;
					file_obj.read((char*)&(newobject->czy_umiejetnosc), sizeof(bool));
					file_obj.read((char*)&(newobject->czas_umiejetnosc), sizeof(int));
					file_obj.read((char*)&(newobject->buff), sizeof(int));

					file_obj.read(&ympD, sizeof(char));

					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;

				}
				else if (strcmp(xympD, "Guarana") == 0) {
					o++;
					Guarana* newobject = new Guarana(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Lis") == 0) {
					o++;
					Lis* newobject = new Lis(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Mlecz") == 0) {
					o++;
					Mlecz* newobject = new Mlecz(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;


					file_obj.read(&ympD, sizeof(char));


					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Owca") == 0) {
					o++;
					Owca* newobject = new Owca(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Trawa") == 0) {
					o++;
					Trawa* newobject = new Trawa(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Wilcze_Jagody") == 0) {
					o++;
					WilczeJagody* newobject = new WilczeJagody(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Wilk") == 0) {
					o++;
					Wilk* newobject = new Wilk(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}
				else if (strcmp(xympD, "Zolw") == 0) {
					o++;
					Zolw* newobject = new Zolw(tmp_pos, new_swiat);

					file_obj.read((char*)load, sizeof(Saving));

					newobject->inicjatywa = load->raz;
					newobject->nastepnykier = load->dwa;
					newobject->nazwaorganizmu = load->trzy;
					newobject->pozycja = load->cztery;
					newobject->sila = load->piec;
					newobject->typorganizmu = load->szesc;
					newobject->wiek = load->siedem;

					file_obj.read(&ympD, sizeof(char));
					*tmp_byt = (Byt*)(newobject);
					((Organizm*)j)->referencja = new_swiat;
				}

				else
				{
					throw "Blad logiczny podczas wczytywania pliku.";

				}


			}
		}

		file_obj.close();
		if (file_obj.good() == 1)
		{
			for (auto &v : (*referencja)->tab)
			{
				for (auto &j : v)
				{
					if (j != nullptr)
						delete j;
				}
				v.clear();
			}

			(*referencja)->tab.clear();

			delete load;
			*referencja = new_swiat;
			throw "Zaladowano plik pomyslnie!";
		}





	}
	else
	{
		throw "Nie znaleziono pliku!";
	}






}


Zapis::~Zapis()
{
}
