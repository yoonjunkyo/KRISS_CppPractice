#include <iostream>
#include<ctime>
#include<cstdlib>
#include"blackjack.h"

using namespace std;

DACK::DACK() {
}
DACK::~DACK() {
}
void DACK::makeDack(int cardArray[70]) {
	int rawArray[14] = { -1,2,3,4,5,6,7,8,9,10,10,10,10 };
	for (int i = 0; i < 70; i++)
	{
		cardArray[i] = rawArray[(i % 13)];
	}
	srand(time(0));
	for (int i = 0; i < 200; i++)
	{
		int x = rand() % 70;
		int y = rand() % 70;

		int temp = cardArray[x];
		cardArray[x] = cardArray[y];
		cardArray[y] = temp;
	}
	cout << endl;

}
