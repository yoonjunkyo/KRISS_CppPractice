#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<iomanip>
#include "bingo.h"

BingoBoard::BingoBoard(int size) {
	real_size = size;
}
BingoBoard::BingoBoard() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			real_array[i][j] = 0;
		}
	}
	real_size = 0;
}
BingoBoard::~BingoBoard() {
}
int BingoBoard::makeBingo(int size)
{

	int x = 0;
	int y = 0;
	for (int p = 1; p < pow(size, 2) + 1; p++)
	{
		x = rand() % size;
		y = rand() % size;
		bool flag = false;
		while (!flag)
		{
			if (real_array[x][y] == 0)
			{
				flag = true;
			}
			else
			{
				x = rand() % size;
				y = rand() % size;
			}
		}
		real_array[x][y] = p;
	}
	return 0;
}

void BingoBoard::printBingo(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (real_array[i][j] == -1) {
				cout << setw(4) << "*";
			}
			else {
				cout << setw(4) << real_array[i][j];
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	return;
}

void BingoBoard::detNum(int Input, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Input == real_array[i][j])
			{
				cout << "»ÌÈù¼ýÀÚ :" << Input << endl;
				real_array[i][j] = -1;
			}
		}
	}
}

void BingoBoard::checkBingo(int size) {
	for (int i = 0; i < size; i++)  //°¡·Î È®ÀÎ
	{
		int count = 0;

		for (int j = 0; j < size; j++)
		{
			if (real_array[i][j] == -1)
			{
				count++;
			}
		}
		if (count == size)
		{
			cout << "ºù°í!" << endl;
		}
	}
	for (int j = 0; j < size; j++)  //¼¼·Î È®ÀÎ
	{
		int count = 0;

		for (int i = 0; i < size; i++)
		{
			if (real_array[i][j] == -1)
			{
				count++;
			}
		}
		if (count == size)
		{
			cout << "ºù°í!" << endl;
		}
	}
	int count1 = 0;
	for (int i = 0; i < size; i++)
	{
		if (real_array[i][i] == -1)
		{
			count1++;
		}
		if (count1 == size)
		{
			cout << "ºù°í!" << endl;
		}
	}
	int count2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (real_array[i][size - i - 1] == -1)
		{
			count2++;
		}
		if (count2 == size)
		{
			cout << "ºù°í!" << endl;
		}
	}
	return;
}