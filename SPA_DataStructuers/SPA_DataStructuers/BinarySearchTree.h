#pragma once

#include<iostream>

#include "BSCvor.h"

using namespace std;

class BST
{
	BSCvor<int>* korijen = nullptr;

	bool dodajRekurzija(BSCvor<int>*& pok, int x)
	{
		if (pok == nullptr)
		{
			pok = new BSCvor<int>(x);
			return true;
		}

		if (pok->info == x)//ne smiju se dodavati duplikati
			return false;

		if (pok->info > x)
     		return dodajRekurzija(pok->lijevoDijete, x);
		
		 if (pok->info < x)
			 return dodajRekurzija(pok->desnoDijete, x);
		
	}
	BSCvor<int>* traziRekurzija(BSCvor<int>*pok,int x)
	{
		if (pok == nullptr)
			return nullptr;

		if (pok->info == x)
			return pok;

		if (pok->info > x)
			return traziRekurzija(pok->lijevoDijete, x);

		if (pok->info < x)
			return traziRekurzija(pok->desnoDijete, x);
	}
	void reciklirajRekurzija(BSCvor<int>*& pok)
	{
		if (pok != nullptr)
		{
			reciklirajRekurzija(pok->lijevoDijete);
			reciklirajRekurzija(pok->desnoDijete);
			cout << " obrisano " << pok->info << endl;
			delete pok;
			pok = nullptr;
		}
	}
public:
	BST()
	{
		korijen = nullptr;
	}
	
	bool dodaj(int x)
	{
		if (korijen == nullptr)
		{
			korijen = new BSCvor<int>(x);
			return true;
		}
		return dodajRekurzija(korijen, x);
	}

	BSCvor<int>* trazi(int x)
	{
		return traziRekurzija(korijen,x);
	}
	void recikliraj()
	{
		cout << "Dealokacija pocetak" << endl;
		reciklirajRekurzija(korijen);
		cout << "Dealokacija gotova" << endl;
	}
	~BST()
	{
		recikliraj();
	}
};
