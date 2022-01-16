#pragma once

#include<iostream>

using namespace std;

void countingSort(int niz[], int n, int exp)
{
	int *tempNiz = new int[n];
	int countingNiz[10] = { 0 };

	//prvo counting niz set
	for (int i = 0; i < n; i++)
	{
		int element = niz[i];
		int cifra = (element /exp) % 10;
		countingNiz[cifra]++;
	}
	//drugo kumulativna suma
	for (int i = 1; i < 10; i++)
		countingNiz[i]+= countingNiz[i - 1];
 
	//trece kopiranje elemenata u pomocni 
	for (int i = n-1; i >= 0; i--)
	{
		int element = niz[i];
		int cifra = (niz[i] / exp) % 10;

		int&tempBrojac = countingNiz[cifra];
		tempBrojac--;
		tempNiz[tempBrojac] = element;

	}

	//cetvrto kopiranje u glavni niz

	for (int i = 0; i < n; i++)
		niz[i] = tempNiz[i];
	
	delete[]tempNiz;
}

int getMax(int niz[], int n)
{
	int temp = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > temp)
			temp = niz[i];
	}
	return temp;
}

void radixSort(int niz[], int n)
{
	int maxV = getMax(niz, n);
	//prolazak kroz cifre
	for (int exp=1;maxV/ exp >0; exp *=10)
	{
		countingSort(niz, n, exp);
	}

}




