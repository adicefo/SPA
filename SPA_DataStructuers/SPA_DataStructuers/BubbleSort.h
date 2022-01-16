#pragma once

#include<iostream>

using namespace std;



void bubbleSort(int niz[], int vel)
{
	bool promjena = true;
	int j = 0;
	//O(n^2)
	while (promjena)
	{
		promjena = false;
		j++;
		for (int i = 0; i < vel-j; i++)
		{
			if (niz[i] > niz[i + 1])
			{
				swap(niz[i], niz[i + 1]);
				promjena = true;
			}
		}
	}

}

void bubbleSortNestedForLoops(int niz[], int vel)
{
	for (int i = 0; i < vel - 1; i++)
	{
		for (int j = 0; j < vel - 1 - i; j++)
		{
			if (niz[j] > niz[j + 1])
				swap(niz[j], niz[j + 1]);
		}

	}
}

