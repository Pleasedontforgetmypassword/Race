#include "Racer.h"
#include <iostream>

using namespace std;

Racer::Racer(char S, float O)
{
	Symbol = S;
	Odds = O;
}

void Racer::Move()
{
	int Luck = rand() % 10000;
	int Chance =  (float) this->Odds * 100;
	if (Chance > Luck)
	{
		this->Progress++;
	}
}