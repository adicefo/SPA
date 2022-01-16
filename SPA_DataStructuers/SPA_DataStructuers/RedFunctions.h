#pragma once

#include "SekvRed.h"
#include "PovRed.h"

#include<iostream>;


using namespace std;

void funkcija(SekvRed& q)
{
	for (int i = 1; i <= 11; i++)
	{
		q.DodajElement(i);
	}
	cout << "Nakon dodavanja: " << endl;
	q.print();
	cout << "\nUklonjeno: \n";
	for (int i = 0; i < 11; i++)
	{
		cout << q.GetElement() << "  ";
	}

}

void funckija2(PovezanRed& q)
{
	for (int i = 0; i < 10; i++)
	{
		q.DodajElement(i * 3);
	}

	cout << "Nakon dodavanja" << endl;
	q.print();

	cout << "\nUklonjeno sa pocetka 3 elementa\n";
	for (int i = 0; i < 3; i++)
	{
		cout << q.UkloniElement() << "  ";

	}
	cout << "\nFIRST IN FIRST OUT\n";
	q.print();
}


