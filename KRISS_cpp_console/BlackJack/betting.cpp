#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"blackjack.h"

using namespace std;
void Betting::runBetting(int playerNum, double player_cash[10])
{
	int betting_cash[10] = { 0 };
	cal_win[9] = { 0 };
	cout << "==============================================================================================" << endl;
	cout << "Betting money" << endl;
	for (int i = 0; i < playerNum; i++) {
		cout << "player " << i + 1 << " enter betting money : ";
		do(cin >> betting_cash[i]);
		while (betting_cash[i] < 0 || betting_cash[i]>1000);
	}
	BLACKJACK blackjack;
	blackjack.appBlackjack(playerNum);
	blackjack.get_result(playerNum, cal_win);
	cout << "==============================================================================================" << endl;
	cout << "Win/Lose Decision" << endl;
	for (int i = 0; i < playerNum; i++) //½ÂÆÐ Ç¥½ÃÇØÁÖ±â
	{
		cout << "player" << i + 1;
		if(cal_win[i]==0)
		{
			cout << "  ÆÐ";
		}
	    else if (cal_win[i] == 1)
		{
			cout << "  ½Â";
		}
		else if (cal_win[i] == 2)
		{
			cout << "  ºí·¢Àè";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < playerNum; i++)
	{
		if (cal_win[i] == 0)
		{
			player_cash[i] = player_cash[i] - betting_cash[i];
		}
		else if (cal_win[i] == 1)
		{
			player_cash[i] = player_cash[i] + betting_cash[i];
		}
		else
		{
			player_cash[i] = player_cash[i] + betting_cash[i] * 3 / 2;
		}
	}
	cout << "==============================================================================================" << endl;
	cout << "Remaining money by player" << endl;
	for (int i = 0; i < playerNum; i++)
	{
		cout << "player  " << i + 1 << "  money: " << player_cash[i] << endl;
	}
};