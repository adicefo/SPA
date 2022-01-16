#pragma once

#pragma once
#include<iostream>

class Lista
{
public:
	virtual void dodaj_na_pocetak(int x)
	{

	}

	virtual void dodaj_na_kraj(int x) {

	}

	virtual int ukloni_sa_pocetka() {
		return 0;
	}

	virtual int ukloni_sa_kraja() {
		return 0;
	}

	virtual bool jel_prazna() {
		return false;
	}

	virtual int operator[](int index) {
		return 0;
	}

	virtual int get_brojac() {
		return  0;
	}
};
