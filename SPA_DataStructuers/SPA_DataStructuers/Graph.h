#pragma once

#include<iostream>
#include<fstream>
#include "ListaPov.h"

using namespace std;

class MatricaSusjedstva
{
	int** matrica=nullptr;
	int vel;
public:
	MatricaSusjedstva(string path,int vel)
	{
		ifstream file(path);
		 matrica = new int* [vel];
		for (int i = 0; i < vel; i++)
		{
			matrica[i] = new int[vel];
		}
		for (int i = 0; i < vel; i++)
		{
			for (int j = 0; j < vel; j++)
			{
				int element;
				file >> element;
				matrica[i][j] = element;
			}
		}
		this->vel = vel;
	}

	int izlazniStepen(int index)
	{
		int suma = 0;
		for (int i = 0; i < vel; i++)
			suma += matrica[index][i];
		return suma;
		
	}
	int ulazniStepen(int index)
	{
		int suma = 0;
		for (int i = 0; i < vel; i++)
		{
			suma += matrica[i][index];
		}
		return suma;
	}
	Lista* susjediTo(int index)
	{
		Lista* tempList = new ListaPov();
		for (int i = 0; i < vel; i++)
		{
			if (matrica[index][i] != 0)
				tempList->dodaj_na_pocetak(matrica[index][i]);
		}
		return tempList;
	}
	Lista* susjediFrom(int index)
	{
		Lista* tempList = new ListaPov();
		for (int i = 0; i < vel; i++)
		{
			if (matrica[i][index] != 0)
				tempList->dodaj_na_pocetak(matrica[i][index]);
		}
		return tempList;
	}
	void ispis()
	{
		for (int i = 0; i < vel; i++)
		{
			for (int j = 0; j < vel; j++)
			{
				cout << matrica[i][j] << "\t";

			}
			cout << "\n";
		}
	}
};
//primjer funkcije
void func()
{
	MatricaSusjedstva M("C:\\Users\\Adi\\OneDrive\\Radna površina\\VS KODOVI\\C++\\STRUKTURE_PODATAKA_I_ALGORITMI\\SPA_DataStructuers\\matrica.txt", 8);

	M.ispis();

	cout << "izlazni stepen za 0: " << M.izlazniStepen(0) << endl;
	cout << "ulazni stepen za 0: " << M.ulazniStepen(0) << endl;



	cout << "izlazni stepen za 0: " << M.susjediTo(0)->get_brojac() << endl;
	cout << "ulazni stepen za 0: " << M.susjediFrom(0)->get_brojac() << endl;


}