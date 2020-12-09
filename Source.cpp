#include <iostream>
#include "hàmmmm.h"

using namespace std;


int main() {
 snake r;
 int Huong = 0;
 char t;
 int xa, ya;
 bool check1, check2;
 srand(time(NULL));
 VeTuong();
 r.Taos(xa,ya);
 //---------------------------Di Chuyen-----------------------------
 while (1) {
	 if (_kbhit()) {
		 t = _getch();
		 if (t == 'a' && Huong != 0) Huong = 2;         
		 if (t == 'w' && Huong != 1) Huong = 3;
		 if (t == 'd' && Huong != 2) Huong = 0;
		 if (t == 's' && Huong != 3) Huong = 1;
		 if (t == 'q') return 0;
	 }
	 r.XoaDuLieu();
	 r.DiChuyen(Huong);
 //-----------------Kiem tra can duoi vs cham tuong-------------------
	 check1 = r.VaTuong();
	 check2 = r.CanDuoi();
	 if (check1 == true || check2 == true) return 0;
	 r.Ve();
//-----------------------An----------------------------
	 if ((r.A[0].x == xa) && (r.A[0].y == ya)){ 
		 r.Them(r.A, xa, ya);
		 Lenght++;
		 r.Taos(xa, ya);
	 }
	 Sleep(150);
  }

 
 return 0;
}


