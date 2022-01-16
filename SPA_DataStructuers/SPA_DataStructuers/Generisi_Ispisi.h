#pragma once
#include<iostream>
using namespace std;


void generisiElemente(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
	{
		niz[i] = rand() % 500 + 1;
	}
}


void ispis(int niz[], int vel,string poruka=" ")
{
	cout << poruka << "\n";
	for (int i = 0; i < vel; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << niz[i] << "  ";
	}
	cout << endl;
}