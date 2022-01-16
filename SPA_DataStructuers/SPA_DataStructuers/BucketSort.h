#pragma once


#include<iostream>

#include"PQueuePov.h"
#include"PQueueSekv.h"


using namespace std;


void bucketSort(int arr[], int n)
{
	PQueueSekv* temp = new PQueueSekv[n];
	int maxValue = getMax(arr, n);
	for (int i = 0; i < n; i++)
	{
		int element = arr[i];
		int position =element * n / (maxValue + 1);
		temp[position].Dodaj(element);
	}

	int tempBrojac = n - 1;
	for (int i = n-1; i >=0;i--)
	{
		PQueueSekv&tempList = temp[i];
		while (!tempList.IsPrazan())
		{
			int x = tempList.Ukloni();
			arr[tempBrojac] = x;
			tempBrojac--;
		}
	}
}