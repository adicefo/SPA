#pragma once



#include<iostream>

#include "PQueue.h"


using namespace std;


//nesortiran
class PQueueSekv : public PQueue
{
	int brojac = 0;
	int max = 10;
	int* niz;
	void prosiriNiz()
	{
		int* novi = new int[max * 3];
		for (int i = 0; i < brojac; i++)
		{
			novi[i] = niz[i];
		}
		delete[]niz;
		niz = novi;
		max *= 3;
		cout << "Niz prosiren-->max je: " << max << endl;

	}
public:
	PQueueSekv()
	{
		niz = new int[max];
	}

	void Dodaj(int x)
	{
		if (brojac == max)
			prosiriNiz();
		niz[brojac] = x;
		brojac++;

	}
	int Ukloni()
	{
		if (IsPrazan())
			throw exception("Prazna lista ");
		int maxIndex = 0, maxValue = niz[0];
		for (int i = 1; i < brojac; i++)
		{
			if (niz[i] > maxValue)
			{
				maxIndex = i;
				maxValue = niz[i];
			}
		}
		niz[maxIndex] = niz[brojac - 1];
		brojac--;
		return maxValue;
	}

	bool IsPrazan() { return brojac == 0; }


};