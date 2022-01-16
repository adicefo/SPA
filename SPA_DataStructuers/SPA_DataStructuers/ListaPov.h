#pragma once
#include<iostream>

#include "Cvor.h"
#include "Lista.h"


using namespace std;

class ListaPov : public Lista
{
	Cvor* prvi = nullptr;
	int brojac = 0;
public:
	//povezane cvorove
	void dodaj_na_pocetak(int x)
	{
		Cvor* n = new Cvor(x, prvi);
		prvi = n;
		brojac++;
	}

	void dodaj_na_kraj(int x) {
		Cvor* t = prvi;

		if (t == nullptr) //ako je prvi nullptr
		{
			prvi = new Cvor(x, nullptr);
			return;
		}
		while (t->next != nullptr)    //kraci nacin
			t = t->next;
		t->next = new Cvor(x, nullptr);            //lakse
		brojac++;





	}

	int ukloni_sa_pocetka() {
		brojac--;
		int x = prvi->info;

		Cvor* t = prvi;
		prvi = prvi->next;
		delete t;

		return x;

	}

	int ukloni_sa_kraja() {
		if (prvi == nullptr)
			throw exception("Prazna lista");
		Cvor* temp = prvi;
		Cvor* pt = nullptr;
		while (temp->next != nullptr)
		{
			pt = temp;
			temp = temp->next;
		}
		//provjera da li ima samo jedan element u listi ako ima prvi je null i uklanjamo ga
		if (pt != nullptr)
		{
			pt->next = nullptr;
		}
		else
			prvi = nullptr;

		int x = temp->info;
		brojac--;
		delete temp;
		return x;




	}
	//zbog hasing-a
	bool ukloniByKey(int element)
	{
		Cvor* pt = nullptr;
		Cvor* t = prvi;
		while (t!=nullptr&&t->info!=element)
		{
			pt = t;
			t = t->next;
		}
		if (t == nullptr)
			return false;
		if (pt == nullptr)
			prvi = prvi->next;
		else
			pt->next = t->next;

		delete t;
		return true;

		
		

		
		

	
	}

	bool jel_prazna()
	{
		return brojac == 0;
	}

	int operator[](int index) {
		if (index < 0 || index >= brojac)
			throw exception("Nevalidna lokacija ");
		Cvor* temp = prvi;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		return temp->info;
	}

	int get_brojac() {
		return brojac;
	}
};