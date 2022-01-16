#pragma once

#include<iostream>
#include "PQueue.h"
#include "Cvor.h"

using namespace std;
//sortiran 
class PQueuePov : public PQueue
{
	Cvor* prvi = nullptr;
	int brojac = 0;
public:
	void Dodaj(int x)
	{
		Cvor* pt = nullptr;
		Cvor* t = prvi;
		while (t != nullptr && t->info < x)//uzlazno sortiranje
		{
			pt = t;
			t = t->next;
		}
		Cvor* novi = new Cvor(x, t);
		if (pt == nullptr)
			prvi = novi;
		else
			pt->next = novi;
		brojac++;

	}

	Tip Ukloni()
	{
		if (IsPrazan())
			throw exception("Lista prazna");
		Cvor* temp = prvi;
		int x = temp->info;
		prvi = prvi->next;
		delete temp;
		brojac--;
		return x;


	}

	bool IsPrazan() { return brojac == 0; }

};
