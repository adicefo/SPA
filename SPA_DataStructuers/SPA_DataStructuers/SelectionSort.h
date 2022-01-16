#pragma once

#include<iostream>

using namespace std;


void selectionSort(int niz[], int vel)
{
	//O(n^2)
	for (int i = 0; i < vel; i++)
	{
		int temp = INT_MAX, index;
		for (int j = i; j < vel; j++)
		{
			if (niz[j] < temp)
			{
				temp = niz[j];
				index = j;
			}
		}
		swap(niz[i], niz[index]);
	}
}