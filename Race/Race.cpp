#include "Racer.h"
#include <iostream>
#include "Track.h"
#include <Windows.h>
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));
	Track track;
	track.Length = 80;
	bool Ready = true;

	cout << "Add racers by typing a character to represent it. Type [0] enter to finish adding." << endl;
	char S;
	do
	{
		cout << "Add Racer: ";
		cin >> S;

		if (S == '0')
		{
			do
			{
				cout << "Ready to Start Race? [y] or [n]" << endl;
				cin >> S;

			} while (S != 'y' && S != 'n');

			if (S == 'n')
			{
				// Do nothing and return to adding players
			}
			else
			{
				Ready = false;
			}
		}
		else
		{
			track.Add_Player(S);
		}

	} while (Ready);

	system("cls");
	cout << "-----------------------------------------------" << endl;
	track.Players_Display();
	cout << "-----------------------------------------------\n" << endl;
	track.Create_Course();
	cout << "Race Begins In" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << endl;
		Sleep(1000);
	}
	system("cls");

	do
	{
		cout << "-----------------------------------------------" << endl;
		track.Players_Display();
		cout << "-----------------------------------------------\n" << endl;

		track.Display();
		track.Update();
		Sleep(1750);
		system("cls");

	} while (!track.Winner());

	cout << "-----------------------------------------------" << endl;
	track.Players_Display();
	cout << "-----------------------------------------------\n" << endl;

	track.Display();

	cout << endl << "Winners are: " << endl;
	for (int u = 0; u < track.Players.size(); u++)
	{
		if (track.Players[u].Progress == track.Length - 1)
		{
			cout << "Player [" << u << "]: " << track.Players[u].Symbol << endl;
		}
	}
}
