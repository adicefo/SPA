#pragma once

#include<iostream>
#include "Cvor.h"

using namespace std;


class PovezanRed
{
	Cvor* pocetak;
	Cvor* kraj;
public:
	PovezanRed()
	{
		pocetak = nullptr;
		kraj = nullptr;
	}

	void DodajElement(int x)
	{
		Cvor* temp = new Cvor(x, nullptr);
		if (kraj != nullptr)
			kraj->next = temp;
		else
			pocetak = temp;
		kraj = temp;
	}

	int UkloniElement()
	{
		Cvor* temp = pocetak;
		pocetak = pocetak->next;
		if (pocetak == nullptr)
			kraj = nullptr;
		int x = temp->info;
		delete temp;
		return x;
	}

	void print(string pre = "", string post = ", ")
	{
		Cvor* temp = pocetak;
		while (temp != nullptr)
		{
			cout << temp->info << "  ";
			temp = temp->next;
		}
	}



};