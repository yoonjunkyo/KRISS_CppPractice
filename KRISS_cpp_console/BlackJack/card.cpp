#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"blackjack.h"

using namespace std;

CARD::CARD(int hand_card[]) {
}
CARD::CARD() {
}
CARD ::~CARD() {
}
void CARD::select_card(int index, int cardArray[70], int player, int my_turn)
{
	hand_card[my_turn / player] = cardArray[index];
}
int CARD::deal_card(int input) {  
	cout << hand_card[input];
	return hand_card[input];
}

int CARD::print_card() {
	for (int i = 0; i < 8; i++) {
		if (hand_card[i]!=0) {
			if (hand_card[i] == -1)
			{
				cout << setw(4) << "A";
			}
			else
			{
				cout << setw(4) << hand_card[i];
			}
		}
	}
	return hand_card[0];
}

int CARD::get_hand_card(int index) {
	return hand_card[index];
}
int CARD::set_hand_card(int index,int changeNum) {
	hand_card[index] = changeNum;
	return 0;
}
int CARD::sum_hand_card() {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum = sum + hand_card[i];
	}
	return sum;
}