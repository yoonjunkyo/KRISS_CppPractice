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
				cout << "player" << i << "!! ACE �� 1 �Ǵ� 11���� �ٲ� �� �ֽ��ϴ�.( [1]:1�� ���� [2]:11���� ����  :)";
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
				cout << "dealer" << "!! ACE �� 1 ���� ����մϴ� :";
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
		cout << endl << "dealer ī�尡 16�̸��̹Ƿ� �߰��� ī�带 �̽��ϴ�." << endl;
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
//CARD player_card[10] �ν��Ͻ��� �Ű������� �����ؼ� Ŭ���� ��� hand_card�� ���� ���� -> hand_card�� �Ӽ��� ������ �� ����
void BLACKJACK::distribute_card(CARD player_card[10],int *cardArray, int playerNum) {

	player_card[0].select_card(0, cardArray, playerNum, 0); //����
	player_card[0].select_card(1, cardArray, playerNum, playerNum); //����
	cout << "==============================================================================================" << endl;
	cout << "Dealer's Card List" << endl;
	cout << "dealer�� ù ��° ī��� ";
	player_card[0].deal_card(0);
	cout << " �Դϴ�."<< endl;

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
			cout << "player" << ((i - 2) % playerNum) + 1 << "�� ī�带 �� �����ðڽ��ϱ�? ( [1]:��]  [0]:�ƴϿ� ):";
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