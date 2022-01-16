#pragma once

#include<iostream>

using namespace std;


void mergeSort(int temp[], int niz[],
	const int list1, const int vel1,
	const int list2, const int vel2)
{
	//O(n)
	//merge klasicni(spajanje 2 niza u jedan)
	int i=list1, j=list2, k=list1;
	while (i < list1 + vel1 && j < list2 + vel2)
	{
		if (niz[i] < niz[j])
			temp[k++] = niz[i++];
		else
			temp[k++] = niz[j++];
	}
	while (i<list1+vel1)
		temp[k++] = niz[i++];
	while (j<list2+vel2)
		temp[k++] = niz[j++];
	for (int k = list1; k < list2+vel2; k++)
		niz[k] = temp[k];

	
	
}
void merge(int temp[], int niz[], int list, int vel)
{
	//O(log2n)
	//cijepanje niza
	if (vel == 1)
		return;
	int list1 = list;
	int vel1 = vel / 2;
	int list2 = list1 + vel1;
	int vel2 = vel - vel1;

	merge(temp, niz, list1, vel1);
	merge(temp, niz, list2, vel2);
	mergeSort(temp, niz, list1, vel1, list2, vel2);

}


