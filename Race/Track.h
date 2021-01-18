#pragma once
#include <vector>
#include "Racer.h"

using namespace std;

class Track
{
public:
	vector<Racer> Players;
	vector<string> Course;
	int Length;
	/* ".........................." [0]
	   ".........................." [1] etc*/
	void Add_Player(char F);
	void Create_Course();
	void Display();
	void Update();
	void Players_Display();
	bool Winner();
};

