#include<iostream>
#include<iomanip>
#include "parking.h"
using namespace std;

int main()
{
	Parking parking;
	while (1) 
	{
		parking.run_parking();
	}
	return 0;
}

void Parking::run_parking()
{
	int(*ptr_park)[2][5] = park_space; //private 배열 멤버를 받아서 포인터에 저장 
	int(*ptr_reserved)[3] = reserved;

	int Input = disp_menu();
	cout << endl;
	if (Input == 1)
	{
		enter_park(ptr_park, reserved); //포인터를 매개변수로 전달
	}
	if (Input == 2)
	{
		exit_park(ptr_park);
	}
	if (Input == 3)
	{
		reserve_park(reserved);
	}
	if (Input == 4)
	{
		print_park(ptr_park, reserved);
	}

}

int Parking::disp_menu() //int disp_menu(void) : 메뉴를 출력하고 선택된 메뉴를 반환
{
	cout << "Display========================================" << endl;
	cout << "1. 주차 " << endl;
	cout << "2. 출차 " << endl;
	cout << "3. 지정차량등록 " << endl;
	cout << "4. 주차현황출력 " << endl;
	cout << "0. 종료 " << endl<<endl;

	cout << "-> 번호선택 : ";
	int Input = 0;
	do	(cin >> Input);
	while	(Input < 0 || Input>4);

	return Input;
}

int Parking::print_park(int(*park_space)[2][5], int(*reserved)[3]) //void print_park(int(*park_space)[2][5], int(*reserved)[3]) : 주차 현황 출력 메소드
{
	int floor = 0;
	cout << "floor : ";
	do	(cin >> floor);
	while (floor < 1 || floor>3);
	print_basement(park_space[floor - 1], floor, reserved);

	return floor;
}

void Parking::print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) //void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) : 주차 현황 출력
{
	cout <<endl<<"* "<< floor << " floor" << endl;
	int count = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (park_space[i][j]==0)
			{
				cout << "[" << setw(5) << count << setw(5) << "]";
			}
			else if (park_space[i][j] > 999)
			{
				cout << "[" << setw(5) << park_space[i][j] << setw(5) << "]";
			}
			else if (park_space[i][j] == -1)
			{
				cout << "[" << setw(5) <<"reserved" << setw(5) << "]" ;
			}

			count++;
		}
		cout << endl;
	}
}
int  Parking::find_space(int(*park_space)[5], int floor, int(*reserved)[3]) //int find_space(int (*park_space)[5], int floor, int (*reserved)[3]); :빈 공간이 얼마 있는지 확인하는 메소드
{
	cout << floor << "층 : " ;
	int count = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (park_space[i][j] == 0)
			{
				count++;
			}
		}
	}
	cout << count<<setw(4);
	return 0;
}
void Parking::enter_park(int(*park_space)[2][5], int(*reserved)[3])
{
	cout << "Enter park=====================================" << endl;
	int car_num = 0;
	cout << "차번입력 : ";
	do	(cin >> car_num);
	while (car_num < 1000 || car_num>9999);
	int temp = check_reservation(reserved, car_num);

	if (temp >=0)
	{
		
		int rsv_floor = reserved[temp][1];
		int rsv_num = reserved[temp][2];
		int i = (rsv_num - 1) / 5;
		int j = (rsv_num - 1) % 5;
		cout << "예약된 자리가 있습니다 -> [" << rsv_floor << " 층 " << rsv_num << "번]"<<endl<<endl;
		park_space[rsv_floor-1][i][j] = car_num;
		
	}
	else
	{
		cout << "남은 자리  ";
		find_space(park_space[0], 1, reserved);
		find_space(park_space[1], 2, reserved);
		find_space(park_space[2], 3, reserved);
		cout << endl<<endl;

		int flag = false;
		while (!flag)
		{
			int select = 0;
			int floor = print_park(park_space, reserved);
			cout <<endl<< floor <<" 층에서 주차 하시겠습니까 ? ([1] 네 [0] 아니요 ) : ";
			cin >> select;

			if (select == 1)
			{
				flag = true;
				int Input = 0;
				int i, j;
				cout <<endl<< "자리 번호를 입력하세요 :";
				cin >> Input;
				i = (Input - 1) / 5;
				j = (Input - 1) % 5;

				park_space[floor - 1][i][j] = car_num;
				print_basement(park_space[floor - 1], floor, reserved);
				cout << endl;
			}
		}
	}
}

void Parking::exit_park(int(*park_space)[2][5])
{
	cout << "Exit_park======================================" << endl;
	int car_num = 0;
	cout << "차번입력 : ";
	do	(cin >> car_num);
	while (car_num < 1000 || car_num>9999);
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (park_space[k][i][j] == car_num)
				{
					park_space[k][i][j] = 0;
				}
			}
		}
	}

}
void Parking::reserve_park(int(*reserved)[3]) 
{
	cout << "Reserve_park===================================" << endl;
	int car_num = 0;
	cout << "차번입력 : ";
	do	(cin >> car_num);
	while (car_num < 1000 || car_num>9999);

	int temp = check_reservation(reserved, car_num);

	if (temp ==-1) 
	{
		cout << "남은 자리  ";
		find_space(park_space[0], 1, reserved);
		find_space(park_space[1], 2, reserved);
		find_space(park_space[2], 3, reserved);
		cout << endl<<endl;

		int flag = false;
		while (!flag)
		{
			int select = 0;
			int floor = print_park(park_space, reserved);
			cout <<endl<< "[1] 계속 [0] 다른 층 선택 : ";
			cin >> select;

			if (select == 1)
			{
				flag = true;
				int Input = 0;
				cout <<endl<< "자리 번호를 입력하세요 :";
				cin >> Input;
				int i = (Input - 1) / 5;
				int j = (Input - 1) % 5;
				if (park_space[floor - 1][i][j] == 0) 
				{
					check_reserved_num(reserved, car_num, floor, Input);
				}
				else
				{
					cout << "이미 등록된 자리입니다." << endl;
				}
			}
		}
	}
	else if(temp >=0)
	{
		cout << "이미 등록된 차량입니다." << endl;
	}
}
int Parking::check_reserved_num(int(*reserved)[3], int car_num, int  floor, int resv_num) //지정차량 저장
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (reserved[i][0] == 0 && count == 0)
		{
			reserved[i][0] = car_num;
			reserved[i][1] = floor;
			reserved[i][2] = resv_num;

			int i = (resv_num - 1) / 5;
			int j = (resv_num - 1) % 5;

			park_space[floor-1][i][j] = -1;

			count++;
		}

	}
	if (count == 0)
	{
		cout << "지정차량 공석이 없음." << endl;
	}
	return 0;
}
int Parking::check_reservation(int(*reserved)[3], int car_num) //지정차량인지 확인 지정차량이면 예약번호 반환 아니면 -1 반환
{
	bool flag = false;
	int rsv_num=0;
	for (int i = 0; i < 3; i++) 
	{
		if (reserved[i][0] == car_num)
		{
			flag = true;
			rsv_num = i;
		}
	
	}
	if (flag == true)
	{
		return rsv_num;
	}
	else if (flag == false)
	{
		return -1;
	}
}