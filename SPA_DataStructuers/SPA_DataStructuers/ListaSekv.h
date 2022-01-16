#pragma once
#include<iostream>
#include "Lista.h"

using namespace std;

class ListaSekv : public Lista
{
	int max = 100;
	int brojac = 0;
	int* N = new int[max];
	void prosiri_niz()
	{
		int* temp = new int[max * 2];
		for (int i = 0; i < brojac; ++i)
		{
			temp[i] = N[i];
		}
		max = max * 2;
		delete[] N;
		N = temp;
	}
public:
	void dodaj_na_pocetak(int x)
	{
		if (brojac == max)
			prosiri_niz();

		for (int i = brojac; i >= 1; i--)
			N[i] = N[i - 1];
		N[0] = x;
		brojac++;
	}

	void dodaj_na_kraj(int x) {
		if (brojac == max)
			prosiri_niz();
		N[brojac] = x,
			brojac++;
	}

	int ukloni_sa_pocetka() {
		if (brojac == 0)
			throw exception("greska... lista je prazna");
		int x = N[0];

		for (int i = 0; i < brojac; i++)
			N[i] = N[i + 1];
		brojac--;
		return x;
	}

	int ukloni_sa_kraja() {
		if (brojac == 0) throw exception("greska... lista je prazna");

		brojac--;
		int x = N[brojac];
		return x;
	}

	bool jel_prazna()
	{
		return brojac == 0;
	}

	int operator[](int index) {
		return N[index];
	}

	int get_brojac() {
		return brojac;
	}
};
