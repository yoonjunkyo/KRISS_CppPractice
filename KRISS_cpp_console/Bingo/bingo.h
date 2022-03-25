#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<iomanip>

using namespace std;
#ifndef TIME_H
#define TIME_H

class BingoBoard
{
private:
	int real_size;
	int real_array[20][20];
public:
	BingoBoard(int size);
	BingoBoard();
	~BingoBoard();
	int makeBingo(int size);
	void printBingo(int size);
	void detNum(int Input, int size);
	void checkBingo(int size);
};

class Bingo
{
private:
	int player_Num;
	int select_Num[400];
public:
	Bingo(int player_Num, int select_Num[400]);
	Bingo();
	~Bingo();
	void runBingo();
	int getRandomNumber(int size);
	int userselectNumber(int size);
	void extractNum(BingoBoard bingo[10],int size,int select_Num[],int playerNum);
};

#endif
