#pragma once

#include<iostream>

using namespace std;


int partition(int niz[], int low, int high)
{
	int pivotIndex = low;
	int pivotElement = niz[high];
	
	for (int i = low; i <high; i++)
	{
		if (niz[i] < pivotElement)
		{
			swap(niz[i], niz[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(niz[pivotIndex], niz[high]);
	return pivotIndex;
	
}

void quickSort(int niz[], int low, int high)
{
	if (low < high)//ako nije maksimalno usitnjen
	{
		int pivotIndex = partition(niz, low, high);
		quickSort(niz, low, pivotIndex - 1);
		quickSort(niz, pivotIndex + 1, high);
	}
}