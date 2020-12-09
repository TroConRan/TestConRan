#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include<ctime>

using namespace std;
int Lenght = 4;

struct Point {
	int x, y;
};

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

void VeTuong() {
	int x = 2, y = 1;//vẽ tường trên 
	while (x <= 100) {
		GotoXY(x, y);
		cout << "+";
		x++;
	}
	x = 100, y = 1;// vẽ tường trái
	while (y <= 25) {
		GotoXY(x, y);
		cout << "+";
		y++;
	}
	x = 2, y = 1; //vẽ tường phải
	while (y <= 25) {
		GotoXY(x, y);
		cout << "+";
		y++;
	}
	y = 25, x = 2;//vẽ tường dưới
	while (x <= 100) {
		GotoXY(x, y);
		cout << "+";
		x++;
	}
}


class snake{ 
public:
	Point A[100];
	snake() {	
		A[0].x = 10; A[0].y = 10;
		A[1].x = 9; A[1].y = 10;
		A[2].x = 8; A[2].y = 10;
		A[3].x = 7; A[2].y = 10;
	}

	void Ve() {
		GotoXY(A[0].x, A[0].y);
		cout << "0";
		for (int i = 1; i < Lenght; i++) {
			GotoXY(A[i].x, A[i].y);
			cout << "o";
		}
	}

	void XoaDuLieu() {

		for (int i = 0; i < Lenght; i++) {
			GotoXY(A[i].x, A[i].y);
			cout << " ";
		}
	}

	void DiChuyen(int Huong) {
		for (int i = Lenght - 1; i > 0; i--) A[i] = A[i - 1];
		if (Huong == 0) A[0].x = A[0].x + 1;
		if (Huong == 1) A[0].y = A[0].y + 1;
		if (Huong == 2) A[0].x = A[0].x - 1;
		if (Huong == 3) A[0].y = A[0].y - 1;
	}

	bool VaTuong() {
		//va tường
		if ((A[0].y == 1) && (A[0]).x >= 2 && (A[0].x <= 100)) return true;
		else if ((A[0].y == 25) && (A[0]).x >= 2 && (A[0].x <= 100)) return true;
		else if ((A[0].x == 2) && (A[0]).y >= 1 && (A[0].y <= 25)) return true;
		else if ((A[0].x == 100) && (A[0]).y >= 1 && (A[0].y <= 25)) return true;
		return false;
	}

	bool CanDuoi() {
		// cắn đuôi
		for (int i = 1; i < Lenght; i++)
			if((A[0].x == A[i].x) && (A[0].y == A[i].y)) return true;
		return false;
	}

	void Taos(int &xa, int &ya) {
		int checkxy;
		xa = rand() % (100 - 2 + 1) + 2;
		ya = rand() % (25 - 1 + 1) + 1;
		for (int i = 0; i < Lenght; i++) {
			if ((xa == A[i].x) && (ya == A[i].y)) checkxy = 1;
		}
		checkxy = 0;
		do {
			xa = rand() % (100 - 2 + 1) + 2;
			ya = rand() % (25 - 1 + 1) + 1;
		} while (checkxy == 1);
		GotoXY(xa, ya);
		cout << "@";
	}
	
	void Them(Point A[],int xa,int ya) {
		for (int i = Lenght; i > 0; i--) {
			A[i].x = A[i - 1].x;
			A[i].y = A[i - 1].y;
		}
		A[0].x = xa;
		A[0].y = ya;
	}


};