#pragma once
#include <iostream>
#include <vector>
#include <string>

class Opowiadacz
{
private:
	std::vector <std::string> dane;
public:
	Opowiadacz();
	void Czysc();
	void Dodaj(std::string tekst);
	bool Opowiedz();
	~Opowiadacz();
};

