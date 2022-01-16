#pragma once

#include<iostream>

using namespace std;

void bubbleDown(int niz[], int n, int i)
{
	
	int ld = 2 * i + 1;//0 indeks se ukljucuje
	int dd = ld+1;
	int largest = i;

	if (ld<n&&niz[largest] < niz[ld])
		largest = ld;
	//ako postoji dd
	if (dd <n && niz[largest] < niz[dd])
		largest = dd;
	if (largest != i)
	{
		swap(niz[i], niz[largest]);
		bubbleDown(niz, n, largest);
	}

}

void heapSort(int niz[], int n)
{
	//na vrhu najveci element
	for (int i = n / 2 - 1; i >= 0; i--)
		bubbleDown(niz, n,i);
	
	for (int i = n-1; i >=0; i--)
	{
		swap(niz[0], niz[i]);
		n--;
		bubbleDown(niz, n, 0);
	}
}