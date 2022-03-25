#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"blackjack.h"

using namespace std;

BLACKJACK::BLACKJACK() {
}
BLACKJACK::~BLACKJACK() {
}
void BLACKJACK::appBlackjack(int Input) {
	DACK dack;
	int cardArray[70] = { 0 };
	dack.makeDack(cardArray);
	int playerNum = Input;
	CARD player_card[10];
	
	distribute_card(player_card,cardArray, playerNum);
	cout << "==============================================================================================" << endl;
	cout << "Change Ace to 1 or 11" << endl;
	for (int i = 1; i < 9; i++)
	{
		for (int index = 0; index < 8; index++)
		{
			int Input = 0;
			if (player_card[i].get_hand_card(index) == -1)
			{
				cout << "player" << i << "!! ACE 를 1 또는 11으로 바꿀 수 있습니다.( [1]:1로 변경 [2]:11으로 변경  :)";
				do(cin >> Input);
				while (Input < 1 || Input>2);
				if (Input == 1) {
					player_card[i].set_hand_card(index, 1);
					cout << player_card[i].get_hand_card(index);
				}
				else
				{
					player_card[i].set_hand_card(index, 11);
				}
				cout << endl;
			}
		}
	}
	cout << "==============================================================================================" << endl;
	cout << "Player Results" << endl;
	for (int i = 1; i < playerNum + 1; i++)
	{
		int result = 0;
		result = player_card[i].sum_hand_card();
		cout << "player " << i << ":";
		player_card[i].print_card();
		cout <<"   result : "<<result<< endl;
	}
	cout << "==============================================================================================" << endl;
	cout << "Dealer Results" << endl;
		for (int index = 0; index < 8; index++)
		{
			int Input = 0;
			if (player_card[0].get_hand_card(index) == -1)
			{
				cout << "dealer" << "!! ACE 를 1 으로 계산합니다 :";
				cin >> Input;
				player_card[0].set_hand_card(index, 1);
				cout << player_card[0].get_hand_card(index);
				cout << endl;
			}
		}
	cout << endl << "dealer card    : ";
	player_card[0].print_card();
	int result = 0;
	result = player_card[0].sum_hand_card();

	cout <<endl<< "==============================================================================================" << endl;
	cout << "Dealer Card Received Again" << endl;
	if (result < 16)
	{
		cout << endl << "dealer 카드가 16미만이므로 추가로 카드를 뽑습니다." << endl;
	}
	
	for (int i = 2; i < 10; i++) {
		if (result < 16)
		{
			player_card[0].select_card(71-i, cardArray, 1, i);
		}
		result = player_card[0].sum_hand_card();
	}
	cout << endl << "dealer card    : ";
	player_card[0].print_card();
	for (int i = 2; i < 10; i++) {
		if (player_card[0].get_hand_card(i) == -1)
		{
			player_card[0].set_hand_card(i, 1);
		}
	}
	cout << "   result : " << result << endl;

	set_result(player_card, playerNum);
}
//CARD player_card[10] 인스턴스를 매개변수로 전달해서 클래스 멤버 hand_card의 값을 변경 -> hand_card의 속성을 유지할 수 있음
void BLACKJACK::distribute_card(CARD player_card[10],int *cardArray, int playerNum) {

	player_card[0].select_card(0, cardArray, playerNum, 0); //딜러
	player_card[0].select_card(1, cardArray, playerNum, playerNum); //딜러
	cout << "==============================================================================================" << endl;
	cout << "Dealer's Card List" << endl;
	cout << "dealer의 첫 번째 카드는 ";
	player_card[0].deal_card(0);
	cout << " 입니다."<< endl;

	cout << "==============================================================================================" << endl;
	cout << "Player's Card List" << endl;
	int j = 0;
	for (int i = 2; i < 2 * playerNum + 2; i++)
	{
		player_card[((i - 2) % playerNum) + 1].select_card(i, cardArray, playerNum, j);
		j++;
	}

	for (int i = 1; i < playerNum + 1; i++)
	{
		cout << "player " << i << ":";
		player_card[i].print_card();
		cout << endl;
	}
	cout << endl;

	int count = 0;
	j = 2;
	int i = 2 * playerNum + 2;
	bool flag = false;
	cout << "==============================================================================================" << endl;
	cout << "Whether to add a player card" << endl;
	int index = 1;
	while (!flag) 
	{
		if (player_card[((i - 2) % playerNum) + 1].die_alive == true)
		{
			int Input = 0;
			cout << "player" << ((i - 2) % playerNum) + 1 << "님 카드를 더 받으시겠습니까? ( [1]:네]  [0]:아니요 ):";
			do(cin >> Input);
			while (Input < 0 || Input>1);
			if (Input == 1)
			{
				player_card[((i - 2) % playerNum) + 1].select_card(index, cardArray, 1, j);
				cout << endl << "player" << ((i - 2) % playerNum) + 1 << " card :";
				player_card[((i - 2) % playerNum) + 1].print_card();
				cout << endl;
				j++;
				index++;
			}
			else
			{
				player_card[((i - 2) % playerNum) + 1].die_alive = false;
				count++;
				i++;
				j = 2;
				cout<<"==============================================================================================" << endl;
			}
		}
		if (count >= playerNum)
		{
			flag = true;
		}
		cout << endl;
	}
}
int BLACKJACK::set_result(CARD player_card[10], int playerNum)
{
	resultArray[9] = { 0 };
	player_card[0].sum_hand_card();
	for (int i = 1; i <= playerNum; i++)
	{
		if(player_card[0].sum_hand_card()>21&& player_card[i].sum_hand_card()<=21)
		{
			resultArray[i - 1] = 1;
		}
		else {
			if (player_card[0].sum_hand_card() < player_card[i].sum_hand_card() && player_card[i].sum_hand_card() <= 21)
			{
				if (player_card[i].sum_hand_card() == 21)
				{
					resultArray[i - 1] = 2;
				}
				else
				{
					resultArray[i - 1] = 1;
				}
			}
			else {
				resultArray[i - 1] = 0;
			}
		}
	}
	return 0;
}

void BLACKJACK::get_result(int playerNum,int cal_cash[9])
{
	for (int i = 0; i < playerNum; i++)
	{
		cal_cash[i]= resultArray[i];
	}
}