#include<iostream>
using namespace std;

class Parking
{
private:
	int park_space[3][2][5] = { 0 };
	int reserved[3][3] = { 0 };
public:
	Parking() {
	};
	~Parking() {
	};
	void run_parking();
	int disp_menu();
	int print_park(int(*park_space)[2][5], int(*reserved)[3]);
	void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]);
	int find_space(int(*park_space)[5], int floor, int(*reserved)[3]);
	void enter_park(int(*park_space)[2][5], int(*reserved)[3]);
	void reserve_park(int(*reserved)[3]);
	int check_reservation(int(*reserved)[3], int num);
	int check_reserved_num(int(*reserved)[3], int car_num, int floor, int resv_num);
	void exit_park(int(*park_space)[2][5]);
};
