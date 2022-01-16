#pragma once

#include "Lista.h"
#include "ListaSekv.h"
#include "ListaPov.h"

using namespace std;



void funkcija(Lista& l)
{
	for (int i = 1; i <= 10; ++i)
	{
		l.dodaj_na_pocetak(i);
	}
	for (int i = 1; i <= 10; ++i)
	{
		l.dodaj_na_kraj(i);
	}

	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << l[i] << endl;
	}
	cout << "----------------------------------------" << endl;


	for (int i = 0; i < 3; ++i)
	{
		cout << "uklonjeno sa sa pocetka: " << l.ukloni_sa_pocetka() << endl;
	}

	for (int i = 0; i < 12; ++i)
	{
		cout << "uklonjeno sa kraja: " << l.ukloni_sa_kraja() << endl;
	}

	while (!l.jel_prazna())
	{
		cout << "uklonjeno sa pocetka: " << l.ukloni_sa_pocetka() << endl;
	}
}
