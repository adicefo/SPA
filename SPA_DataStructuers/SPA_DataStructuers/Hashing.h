#pragma once

#include<iostream>
#include "ListaPov.h"

using namespace std;


class ChainHasing
{
	int n = 10;
	ListaPov* Niz = new ListaPov[n];
	int brojac = 0;

	int hashFunction(int element)
	{
		return element % n;
	}
	
public:
	void dodaj(int element)
	{
		if (brojac == n)
			throw exception("Prekoracenje opsega");
 		int index = hashFunction(element);
		Niz[index].dodaj_na_pocetak(element);
		brojac++;
	}
	bool ukloni(int element)
	{
		if (brojac == 0)
			throw exception("Tabela prazna");
		int index = hashFunction(element);
		return Niz[index].ukloniByKey(element);
	}
	
};

