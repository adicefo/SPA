#pragma once
#include<iostream>

using namespace std;
//O(n^2)

void insertionSort(int niz[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j!=0&&niz[j-1]>niz[j])
		{
			swap(niz[j - 1], niz[j]);
			j--;
		}
	}
}

void insertionSortNestedForLoops(int niz[], int vel)
{
	for (int i = 1; i < vel; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (niz[j - 1] > niz[j])
				swap(niz[j - 1], niz[j]);
			else 
				break;
		}
	}
}