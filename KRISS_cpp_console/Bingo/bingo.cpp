#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "bingo.h"

Bingo::Bingo(int player_Num, int select_Num[400]) {
}
Bingo::Bingo() {

	int select_Num[400] = { 0 };
	int player_Num = 0;
}
Bingo ::~Bingo() {
}
void Bingo::runBingo() {

	int select_Num[400] = { 0 };

	int playerNum = 0;  //player number �Է�
	cout << "playerNum :";
	cin >> playerNum;
	BingoBoard* bingo = new BingoBoard[playerNum+1];
	cout << "������ ����� �Է��ϼ��� :"; // bingo boardsize �Է�
	int size;
	cin >> size;
	srand(time(0));
	for (int i = 1; i < playerNum + 1; i++)
	{
		cout << "player" << i << endl;

		bingo[i].makeBingo(size);  //�ʱ� ������ ���� �� ���

		bingo[i].printBingo(size);
	}
	while (1)
	{
	extractNum(bingo, size,select_Num, playerNum);
	}
	delete bingo;
}
int Bingo::getRandomNumber(int size) {
	srand(time(0));
	bool flag = false;
	int randomNum = rand() % (int)pow(size, 2) + 1;
	return randomNum;
}
int Bingo::userselectNumber(int size) {
	int userNum = 0;
	cout << "���ڸ� �Է��ϼ��� :";
	cin >> userNum;
	return userNum;
}
void Bingo::extractNum(BingoBoard bingo[10], int size, int select_Num[], int playerNum)
{	bool flag = false;
	int temp = 0;
	int p = 0;
	int way_Num;
	cout << "���� ���� ����� ���� [1:����][2:����] : ";
	cin >> way_Num;

	while (!flag)  //���� ���� ����� ���� ���� �ݺ�
	{
		flag = true;
		if (way_Num == 1)
		{
			temp = getRandomNumber(size);
		}
		else
		{
			temp = userselectNumber(size);
		}

		for (int i = 0; i < 400; i++)
		{
			if (temp == select_Num[i])
			{
				flag = false;
				p--;
			}
		}
		select_Num[p] = temp;
		p++;
	}
	for (int i = 1; i < playerNum + 1; i++)
	{
		bingo[i].detNum(temp, size);
		cout << "player" << i << endl;
		bingo[i].checkBingo(size);
		bingo[i].printBingo(size);
	}
}