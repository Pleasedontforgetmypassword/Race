#include "Track.h"
#include <vector>
#include <iostream>
#include "Racer.h"
#include <ctime>
#include <string>

using namespace std;

void Track::Add_Player(char F)
{
	float Odds = (rand() % 10000); 
	this->Players.push_back( Racer(F, Odds / 100) );
}

void Track::Create_Course()
{
	for (int i = 0; i < this->Players.size(); i++)
	{
		string Race = "";
		Race += this->Players[i].Symbol;
		for (int j = 1; j < this->Length; j++)
		{
			Race += ".";
		}
		this->Course.push_back(Race);
	}
}

void Track::Display()
{
	// Number at start will be 8 chars long;
	for (int i = 0; i < this->Course.size(); i++)
	{
		cout << '[' << i << ']';

		string N = to_string(i);

		int remain = 8 - (2 + N.length());

		for (int j = 0; j < remain; j++)
		{
			cout << ' ';
		}

		cout << this->Course[i] << " " << "||"<<endl;

	}
}

void Track::Update()
{
	for (int y = 0; y < this->Players.size(); y++)
	{
		this->Course[y][this->Players[y].Progress] = '.';
		this->Players[y].Move();
		this->Course[y][this->Players[y].Progress] = this->Players[y].Symbol;
	}
}

void Track::Players_Display()
{
	for (int r = 0; r < this->Players.size(); r++)
	{
		cout << "Player [" << r << "]: " << " " << this->Players[r].Symbol << "    Odds:   " << this->Players[r].Odds << "%" << endl;;
	}
}

bool Track::Winner()
{
	for (int u = 0; u < this->Players.size(); u++)
	{
		if (this->Players[u].Progress == this->Length - 1)
		{
			return true;
		}
	}
	return false;
}