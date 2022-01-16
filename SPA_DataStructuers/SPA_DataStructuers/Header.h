#pragma once

#include<iostream>

using namespace std;


void mergeSort(int temp[], int niz[], 
	const int list1, const int vel1,
	const int list2, const int vel2)
{
}

void cijepajNiz(int temp[],int niz[],int list, int vel)
{
	if (vel == 1)
		return;
	int list1 = list;
	int vel1 = vel / 2;
	int list2 = list1 + vel1;
	int vel2 = vel - vel1;

	cijepajNiz(temp,niz, list1, vel1);
	cijepajNiz(temp,niz, list2, vel2);

	mergeSort(temp, niz, list1, vel1, list2, vel2);
}