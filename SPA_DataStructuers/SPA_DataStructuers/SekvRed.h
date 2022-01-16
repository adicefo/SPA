#pragma once


#include<iostream>


using namespace std;


class SekvRed
{
	int brojac = 0;
	int max = 100;
	int pocetak = 0;
	int kraj = 0;
	int* niz;

public:
	SekvRed()
	{
		niz = new int[max];
	}
	void DodajElement(int x)
	{
		if (brojac == max)
			throw exception("Prazna lista");
		niz[kraj] = x;
		kraj++;
		brojac++;
		if (kraj == max)
			kraj = 0;

	}
	int GetElement()
	{
		if (!GetBrojac())
			throw exception("Prazna lista");
		int x = niz[pocetak];
		brojac--;
		pocetak++;
		if (pocetak == max)
			pocetak = 0;
		return x;

	}

	int GetBrojac()	const { return brojac; }
	int operator[](int index)
	{
		if (index<0 || index>brojac - 1)
			throw exception("Nevalidan index");
		return niz[index];
	}

	void print()
	{
		for (int i = 0; i < brojac; i++)
			cout << niz[i] << "  ";


	}

};