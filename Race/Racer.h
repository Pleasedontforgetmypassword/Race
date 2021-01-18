#pragma once
#include <iostream>

using namespace std;

class Racer
{
public:
	char Symbol;
	int Progress = 0;
	float Odds;
	Racer(char S, float O);
	void Move();

};

