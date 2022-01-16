#pragma once
#include<iostream>

//radi polymorphism-a
class PQueue
{

public:
	virtual void Dodaj(int x) = 0;
	virtual int Ukloni() = 0;
	virtual bool IsPrazan() = 0;


};