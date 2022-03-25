#include <iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"blackjack.h"

using namespace std;

int main()
{
	cout << "==============================================================================================" << endl;
	cout << "Number of Players" << endl;
	int playerNum = 0;
	cout << "playerNum: ";
	do(cin >> playerNum);
	while(playerNum < 1 || playerNum>9);
	double player_cash[10] = { 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000 };
	cout << "==============================================================================================" << endl;
	cout << "Player's Money" << endl;
	for (int i = 0; i < playerNum; i++)
	{
		cout << "player  " << i + 1 << "  money: " << player_cash[i] << endl;
	}
	Betting betting[10];
	for (int i = 0; i < 10; i++) {
		betting[0].runBetting(playerNum, player_cash);
		cout << "==============================================================================================" << endl;
		cout << "Press any key to start the next game." << endl;
		int asd;
		cin >> asd;
		cout << "==============================================================================================" << endl;
		cout << "Next game start!!" << endl;
	}
	return 0;

}
