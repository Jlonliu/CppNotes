#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"tabtenn0.h"
using namespace std;
int main(void) {
	{
		RatedPlayer rplayer1(1140,"Chuck", "Blizzard", false);
		TableTennisPlayer player1("Tara", "Boomdea", true);
		rplayer1.Name();
		if (rplayer1.HasTable()) 
			cout << ": has a table.\n";
		else
			cout << ": hasn't a table.\n";
		player1.Name();
		if (player1.HasTable())
			cout << ": has a table.\n";
		else
			cout << ": hasn't a table.\n";
		cout << "Name: ";
		rplayer1.Name();
		cout << "; Rating: " << rplayer1.Rating() << endl;
		RatedPlayer rplayer2(1212, player1);
		cout << "Name: ";
		rplayer2.Name();
		cout << "; Rating: " << rplayer2.Rating() << endl;
	}
	
	getchar(); return 0;
}