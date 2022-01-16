#pragma once

#include<iostream>

#include "PQueue.h"
#include "PQueuePov.h"
#include "PQueueSekv.h"


void funkcija(PQueue& pq)
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		pq.Dodaj(rand() % 100);
	}
	while (!pq.IsPrazan())
	{
		cout << "Uklonjeno: " << pq.Ukloni() << endl;
	}
}
