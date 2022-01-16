#pragma once

#include<iostream>
#include"PQueue.h"

using namespace std;


class PQHeap:public PQueue
{
	int brojac = 0;
	int max = 15;
	int* niz = new int[max];


	void rotirajPoIndeksu(int& i1, int& i2)
	{
		int temp = niz[i1];
		niz[i1] = niz[i2];
		niz[i2] = temp;
	}
	void bubbleUp(int i)
	{
		//i->dijete,r->roditelj
		if (i == 1)
			return;
		int r = i / 2;
		if (niz[i] > niz[r])
		{
			rotirajPoIndeksu(i, r);
			bubbleUp(r);
		}

	}

	void bubbleDown(int i)
	{
		//rekurzija,bazni slucaj da li je list
		if (2 * i > brojac)
			return;

		int maxInd = i;

		int LD = 2 * i;
		int DD = LD + 1;

		if (niz[LD] > niz[maxInd])
		{
			maxInd = LD;
		}

		if (DD <= brojac && niz[DD] > niz[maxInd])
		{
			maxInd = DD;
		}

		//rotacija izmedji cvor "i" i djeteta koje ima vecu vrijednost
		//
		if (maxInd != i)
		{
			rotirajPoIndeksu(i, maxInd);
			bubbleDown(maxInd);
		}

	}

public:
	void Dodaj(int x)
	{
		if (brojac == max)
			throw exception("Lista puna");
		brojac++;
		niz[brojac] = x;
		bubbleUp(brojac);

	}
	int Ukloni()
	{
		int x = niz[1];
		niz[1] = niz[brojac];
		brojac--;
		bubbleDown(1);
		return x;

	}

	bool IsPrazan() { return brojac == 0; }

};

void test(PQHeap& pq)
{
	for (int i = 10; i > 0; i--)
	{
		pq.Dodaj(i);
	}
	while (!pq.IsPrazan())
	{
		cout << "Uklonjeno: " << pq.Ukloni() << endl;
	}
}