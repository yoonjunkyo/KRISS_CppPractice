#include<iostream>

using namespace std;

class DACK
{
private:

public:
	DACK(int cardArray[140]){
	};
	DACK();
	~DACK();
	void makeDack(int cardArray[70]);
};

class CARD
{
private:
	DACK dack;
	int hand_card[8] = { 0 };
public:
	CARD(int hand_card[]);
	CARD();
	~CARD();
	void select_card(int index, int cardArray[70], int player,int my_turn);
	int print_card();
	int deal_card(int input);
	bool die_alive = true;
	int get_hand_card(int index);
	int set_hand_card(int index, int changeNum);
	int sum_hand_card();
};

class BLACKJACK
{
private:
	int resultArray[10] = {0};
public:
	BLACKJACK();
	~BLACKJACK();
	void appBlackjack(int playerNum);
	void distribute_card(CARD player_card[10],int *cardArray, int playerNum);
	int set_result(CARD player_card[10],int playerNum);
	void get_result(int playerNum, int cal_cash[9]);
};

class Betting
{
private:
	
	int cal_win[10] = { 0 };
public:
	Betting(int num) {
	};
	Betting() {
	};
	~Betting() {
	};
	void runBetting(int playerNum,double player_cash[10]);
};