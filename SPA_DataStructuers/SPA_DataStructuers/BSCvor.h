#pragma once


#include<iostream>

using namespace std;

template <typename T>
class BSCvor
{
public:
	T info;
	BSCvor* lijevoDijete;
	BSCvor* desnoDijete;
	BSCvor(T info)
	{
		this->info = info;
		this->lijevoDijete = nullptr;
		this->desnoDijete = nullptr;
	}

};

ostream& operator<<(ostream& out, const BSCvor<int>& x)
{
	out << x.info;
	return out;
}