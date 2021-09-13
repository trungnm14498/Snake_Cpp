#include <iostream>
#include "mylib.h"
#include "Ham_su_dung_lai.h"
using namespace std;

// Ham can dung
void menu();
void ve_tuong1();
void ve_tuong2();
void play1();
void play2();
void play3();
void play4();
void play5();
void play6();
void play7();
void tao_ran3();
void tao_qua();
void tao_qua2();
int kt_ran_cham_ran();
void ran_an_qua();
void ran_an_qua2();
void ran_an_qua3();
void ran_an_qua5();
void ran_an_qua7(int &check);
bool game_over();
bool game_over2();
bool game_over3();
void thong_bao();
void thong_bao2();
void thong_bao3();
void thong_bao4();
void thong_bao5();
void thong_bao6();
void thong_bao7();

void main()
{
	ShowCur(0);
	srand(time(NULL));
	menu();
	_getch();
}

void menu()
{
	bool kt_menu = true;
	while (kt_menu)
	{
		cout << "\n\t\t\t\t\t    *** SNAKE GAME MENU ***" << endl;
		cout << " 1. Box" << endl;
		cout << " 2. Box But More Walls" << endl;
		cout << " 3. Solo PvP" << endl;
		cout << " 4. Classic" << endl;
		cout << " 5. Yin Yang" << endl;
		cout << " 6. Color Snake" << endl;
		cout << " 7. Twins Snake" << endl;
		cout << " 0. Exit" << endl;
		int choice = 0;
		choose: 
			cout << "\n Choose the Game Mode or Exit: "; cin >> choice;

		switch (choice)
		{
		case 1:
			diem_cao = 0;
			system("cls");
			play1();
			break;
		case 2:
			diem_cao = 0;
			system("cls");
			play2();
			break;
		case 3:
			system("cls");
			play3();
			break;
		case 4:
			diem_cao = 0;
			system("cls");
			play4();
			break;
		case 5:
			diem_cao = 0;
			system("cls");
			play5();
			break;
		case 6:
			diem_cao = 0;
			system("cls");
			play6();
			break;
		case 7:
			diem_cao = 0;
			system("cls");
			play7();
			break;
		case 0:
			exit(0);
			kt_menu = false;
		default:
			goto choose;
		}
	}
}

void play1()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	tao_qua();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int check = 2;		// 0: di xuong
						// 1: di len
						// 2: di sang phai
						// 3: di sang trai

	//-----play -----
	while (true)
	{
		
		
		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//----- print -----
		ve_ran(3,toa_do_x,toa_do_y,sl);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//------ borders -----
		if (game_over())
		{
			SetColor(7);
			break;
		}	
		//------ handle ------
		di_chuyen_ran(x, y,toa_do_x,toa_do_y,sl);
		ran_an_qua();
		doi_mau();
		gotoXY(0, 0);
		cout << "Score: " << diem << endl;
		cout << "MaxS: " << diem_cao;
		gotoXY(50, 28);
		cout << "[***] BOX MODE [***]";
		//------ speed -----
		toc_do(speed);				
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 30;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao();
}

void play2()
{
	// Setting
	ve_tuong2();
	tao_ran();
	tao_qua2();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int check = 2;		// 0: di xuong
						// 1: di len
						// 2: di sang phai
						// 3: di sang trai
	//-----play -----
	while (true)
	{


		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//----- print -----
		ve_ran(3, toa_do_x, toa_do_y, sl);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//------- borders ---------
		if (game_over2())
		{
			SetColor(7);
			break;
		}
		//------ handle ------
		di_chuyen_ran(x, y, toa_do_x, toa_do_y, sl);
		ran_an_qua2();
		doi_mau();
		gotoXY(0, 0);
		cout << "Score: " << diem << endl;
		cout << "MaxS: " << diem_cao;
		gotoXY(45, 28);
		cout << "[***] BOX WITH MORE WALLS MODE [***]";
		//------ speed -----
		toc_do(speed);
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 30;
		}
		Sleep(speed);
	}
	thong_bao2();
}

void play3()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	tao_ran3();
	tao_qua();
	int x1 = toa_do_x[0];
	int y1 = toa_do_y[0];
	int x2 = toa_do_x2[0];
	int y2 = toa_do_y2[0];
	int check = 2;		// 0, 4: di xuong
						// 1, 5: di len
						// 2, 6: di sang phai
						// 3, 7: di sang trai
	int check2 = 7;
	//-----play -----
	while (true)
	{


		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		gotoXY(toa_do_x2[sl2], toa_do_y2[sl2]);
		cout << " ";
		//----- print -----
		ve_ran(3, toa_do_x, toa_do_y, sl);
		ve_ran(14, toa_do_x2, toa_do_y2, sl2);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			if (c == 'w' && check2 != 5)
			{
				check2 = 4;
			}
			else if (c == 's' && check2 != 4)
			{
				check2 = 5;
			}
			else if (c == 'd' && check2 != 7)
			{
				check2 = 6;
			}
			else if (c == 'a' && check2 != 6)
			{
				check2 = 7;
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y1++;
		}
		else if (check == 1)
		{
			y1--;
		}
		else if (check == 2)
		{
			x1++;
		}
		else if (check == 3)
		{
			x1--;
		}

		if (check2 == 4)
		{
			y2--;
		}
		else if (check2 == 5)
		{
			y2++;
		}
		else if (check2 == 6)
		{
			x2++;
		}
		else if (check2 == 7)
		{
			x2--;
		}
		//------ borders -----
		if (game_over3())
		{
			break;
		}
		//------ handle ------
		di_chuyen_ran(x1, y1, toa_do_x, toa_do_y, sl);
		di_chuyen_ran(x2, y2, toa_do_x2, toa_do_y2, sl2);
		ran_an_qua3();
		gotoXY(0, 0);
		cout << " P1: " << diem << endl;
		cout << " P2: " << diem2;
		gotoXY(50, 28);
		cout << "[***] PVP MODE [***]";

		//------ speed -----
		speed = 75;
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 20;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao3();
}

void play4()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	tao_qua();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int check = 2;		// 0: di xuong
						// 1: di len
						// 2: di sang phai
						// 3: di sang trai

	//-----play -----
	while (true)
	{


		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//----- print -----
		ve_ran(3,toa_do_x,toa_do_y,sl);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//------ gameover -----
		if (kt_ran_cham_than(sl, toa_do_x, toa_do_y))
		{
			SetColor(7);
			break;
		}
		if (x == 110)
		{
			x = 11;
		}
		else if (x == 10)
		{
			x = 109;
		}
		if (y == 1)
		{
			y = 26;
		}
		else if (y == 27)
		{
			y = 2;
		}
		//------ handle ------
		di_chuyen_ran(x, y, toa_do_x, toa_do_y, sl);
		ran_an_qua();
		doi_mau();
		gotoXY(0, 0);
		cout << "Score: " << diem << endl;
		cout << "MaxS: " << diem_cao;
		gotoXY(49, 28);
		cout << "[***] CLASSIC MODE [***]";
		//------ speed -----
		toc_do(speed);
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 30;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao4();
}

void play5()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	tao_ran3();
	tao_qua();
	int x1 = toa_do_x[0];
	int y1 = toa_do_y[0];
	int x2 = toa_do_x2[0];
	int y2 = toa_do_y2[0];
	int check = 2;		// 0, 4: di xuong
						// 1, 5: di len
						// 2, 6: di sang phai
						// 3, 7: di sang trai
	int check2 = 7;
	//-----play -----
	while (true)
	{


		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		gotoXY(toa_do_x2[sl2], toa_do_y2[sl2]);
		cout << " ";
		//----- print -----
		ve_ran(3, toa_do_x, toa_do_y, sl);
		ve_ran(14, toa_do_x2, toa_do_y2, sl2);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1 && check2 != 5)
				{
					check = 0;
					check2 = 4;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
					check2 = 5;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
					check2 = 7;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
					check2 = 6;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y1++;
		}
		else if (check == 1)
		{
			y1--;
		}
		else if (check == 2)
		{
			x1++;
		}
		else if (check == 3)
		{
			x1--;
		}

		if (check2 == 4)
		{
			y2--;
		}
		else if (check2 == 5)
		{
			y2++;
		}
		else if (check2 == 6)
		{
			x2++;
		}
		else if (check2 == 7)
		{
			x2--;
		}
		//------ borders -----
		if (game_over3())
		{
			break;
		}
		//------ handle ------
		di_chuyen_ran(x1, y1, toa_do_x, toa_do_y, sl);
		di_chuyen_ran(x2, y2, toa_do_x2, toa_do_y2, sl2);
		ran_an_qua5();
		doi_mau();
		gotoXY(0, 0);
		cout << " Score: " << diem << endl;
		cout << " MaxS: " << diem_cao;
		gotoXY(50, 28);
		cout << "[***] YIN YANG MODE [***]";

		//------ speed -----
		toc_do(speed);
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 20;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao5();
}

void play6()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	tao_qua();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int mau = 7;
	int check = 2;		// 0: di xuong
						// 1: di len
						// 2: di sang phai
						// 3: di sang trai

	//-----play -----
	while (true)
	{
		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//----- print -----
		ve_ran_mau(3, toa_do_x, toa_do_y, sl, mau);
		ve_qua_mau(mau);
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//------ borders -----
		if (game_over())
		{
			SetColor(7);
			break;
		}
		//------ handle ------
		di_chuyen_ran(x, y, toa_do_x, toa_do_y, sl);
		if (kt_ran_an_qua() == 1)
		{
			mau = rand() % (15 - 2 + 1) + 2;
		}
		ran_an_qua();
		
		gotoXY(0, 0);
		SetColor(7);
		cout << "Score: " << diem << endl;
		cout << "MaxS: " << diem_cao;
		gotoXY(50, 28);
		SetColor(7);
		cout << "[***] COLOR MODE [***]";
		//------ speed -----
		toc_do(speed);
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 30;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao6();
}

void play7()
{
	//BUILD GAME
	//----- setting -----
	ve_tuong1();
	tao_ran();
	ve_ran(3, toa_do_x, toa_do_y, sl);
	tao_qua();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int check = 2;		// 0: di xuong
						// 1: di len
						// 2: di sang phai
						// 3: di sang trai

	//-----play -----
	while (true)
	{
		//----- clear old data -----
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//----- print -----
		x = toa_do_x[0];
		y = toa_do_y[0];
		ve_ran(3, toa_do_x, toa_do_y, sl);
		ve_qua();
		//------ controls -----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				char c = _getch();
				if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
			}
			else if (c == 27)
			{
				gotoXY(0, 29);
				cout << "GAME PAUSED - Press any key to continue the game!";
				_getch();
				gotoXY(0, 29);
				cout << "                                                 ";
			}
		}
		//------ move -----
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		if (game_over())
		{
			SetColor(7);
			break;
		}
		//------ handle ------
		di_chuyen_ran(x, y, toa_do_x, toa_do_y, sl);
		ran_an_qua7(check);
		doi_mau();
		gotoXY(0, 0);
		cout << "Score: " << diem << endl;
		cout << "MaxS: " << diem_cao;
		gotoXY(50, 28);
		cout << "[***] TWINS MODE [***]";
		//------ speed -----
		toc_do(speed);
		if (check == 0 || check == 1)	// Xu ly khi ran di len hoac xuong bi nhanh hon luc di ngang
		{
			speed += 30;
		}
		Sleep(speed);
	}
	//------ Notifications ------
	thong_bao7();
}

void ve_tuong1()
{
	for (int x = 9; x <= 111;x++)
	{
		gotoXY(x, 1);
		cout << char(196);
		gotoXY(x, 27);
		cout << char(196);
	}
	
	for (int y = 1;y <= 27;y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(110, y);
		cout << char(179);
	}
}

void ve_tuong2()
{
	// Ve tuong ngoai
	for (int x = 9; x <= 111;x++)
	{
		gotoXY(x, 1);
		cout << char(196);
		gotoXY(x, 27);
		cout << char(196);
	}

	for (int y = 1;y <= 27;y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(110, y);
		cout << char(179);
	}
	
	// Ve cac tuong phia trong
	for (int x = 22; x <= 54;x++)
	{
		gotoXY(x, 7);
		cout << char(196);
		gotoXY(x, 21);
		cout << char(196);
	}

	for (int x = 66; x <= 98;x++)
	{
		gotoXY(x, 7);
		cout << char(196);
		gotoXY(x, 21);
		cout << char(196);
	}

	for (int y = 7;y <= 12;y++)
	{
		gotoXY(22, y);
		cout << char(179);
		gotoXY(98, y);
		cout << char(179);
	}

	for (int y = 16;y <= 21;y++)
	{
		gotoXY(22, y);
		cout << char(179);
		gotoXY(98, y);
		cout << char(179);
	}

}

void tao_ran3()
{
	int x = 104, y = 26;
	for (int i = 0;i < sl2;i++)
	{
		toa_do_x2[i] = x++;
		toa_do_y2[i] = y;
	}
}

bool game_over()
{
	if (kt_ran_cham_than(sl,toa_do_x,toa_do_y))
	{
		Sleep(300);
		return true;
	}
	else if (toa_do_x[0] == 10 || toa_do_x[0] == 110 || toa_do_y[0] == 1 || toa_do_y[0] == 27 )
	{
		Sleep(300);
		return true;
	}
	return false;
}

bool game_over2()
{
	if (kt_ran_cham_than(sl, toa_do_x, toa_do_y))
	{
		Sleep(300);
		return true;
	}
	// Biên ngoài
	else if (toa_do_x[0] == 10 || toa_do_x[0] == 110 || toa_do_y[0] == 1 || toa_do_y[0] == 27)
	{
		Sleep(300);
		return true;
	}
	// Các biên trong nằm ngang
	if ((toa_do_x[0] >= 22 && toa_do_x[0] <= 54) || (toa_do_x[0] >= 66 && toa_do_x[0] <= 98))
	{
		if (toa_do_y[0] == 7 || toa_do_y[0] == 21)
		{
			Sleep(300);
			return true;
		}
	}
	// Các biên trong nằm dọc
	if ((toa_do_y[0] >= 7 && toa_do_y[0] <= 12) || (toa_do_y[0] >= 16 && toa_do_y[0] <= 21))
	{
		if (toa_do_x[0] == 22 || toa_do_x[0] == 98)
		{
			Sleep(300);
			return true;
		}
	}
	return false;
}

bool game_over3()
{
	if (kt_ran_cham_than(sl, toa_do_x, toa_do_y) || kt_ran_cham_than(sl2, toa_do_x2, toa_do_y2))
	{
		Sleep(300);
		return true;
	}
	else if (toa_do_x[0] == 10 || toa_do_x[0] == 110 || toa_do_y[0] == 1 || toa_do_y[0] == 27)
	{
		Sleep(300);
		return true;
	}
	else if (toa_do_x2[0] == 10 || toa_do_x2[0] == 110 || toa_do_y2[0] == 1 || toa_do_y2[0] == 27)
	{
		Sleep(300);
		return true;
	}
	if (kt_ran_cham_ran()==1 || kt_ran_cham_ran() == 2)
	{
		Sleep(300);
		return true;
	}
	return false;
}

bool kt_qua_va_tuong()
{
	if ((xqua >= 22 && xqua <= 54) || (xqua >= 66 && xqua <= 98))
	{
		if (yqua == 7 || yqua == 21)
		{
			return true;
		}
	}
	// Các biên trong nằm dọc
	if ((yqua >= 7 && yqua <= 12) || (yqua >= 16 && yqua <= 21))
	{
		if (xqua == 22 || xqua == 98)
		{
			return true;
		}
	}
	return false;
}

int kt_ran_cham_ran()
{
	for (int i = 0; i < sl;i++)
	{
		for (int j = 0; j < sl2;j++)
		{
			if (toa_do_x[0] == toa_do_x2[j] && toa_do_y[0] == toa_do_y2[j])
				return 1;
			else if (toa_do_x2[0] == toa_do_x[i] && toa_do_y2[0] == toa_do_y[i])
				return 2;
		}
	}
	return 0;
}

void tao_qua()
{
	do {
		xqua = rand() % (109 - 11 + 1) + 11;
		yqua = rand() % (26 - 2 + 1) + 2;
	} while (kt_ran_va_qua());
}

void tao_qua2()
{
		do {
			xqua = rand() % (109 - 11 + 1) + 11;
			yqua = rand() % (26 - 2 + 1) + 2;
		} while (kt_ran_va_qua() || kt_qua_va_tuong());
}

void ran_an_qua()
{
	if (kt_ran_an_qua() == 1)
	{
		sl++;
		tao_qua();
		ve_qua();
		diem++;
	}
	if (diem > diem_cao)
	{
		diem_cao = diem;
	}
}

void ran_an_qua2()
{
	if (kt_ran_an_qua()==1)
	{
		sl++;
		tao_qua2();
		ve_qua();
		diem++;
	}
	if (diem > diem_cao)
	{
		diem_cao = diem;
	}
}

void ran_an_qua3()
{
	if (kt_ran_an_qua()==1)
	{
		sl++;
		tao_qua();
		ve_qua();
		diem++;
	}
	else if (kt_ran_an_qua() == 2)
	{
		sl2++;
		tao_qua();
		ve_qua();
		diem2++;
	}
}

void ran_an_qua5()
{
	if (kt_ran_an_qua() == 1 || kt_ran_an_qua() == 2)
	{
		sl++;
		sl2++;
		tao_qua();
		ve_qua();
		diem++;
	}
	if (diem > diem_cao)
	{
		diem_cao = diem;
	}
}

void ran_an_qua7(int &check)
{
	if (kt_ran_an_qua() == 1)
	{
		sl++;		
		tao_qua();
		for (int i = 0; i < sl/2; i++)
		{
			swap(toa_do_x[i], toa_do_x[sl - 1 - i]);
			swap(toa_do_y[i], toa_do_y[sl - 1 - i]);
		}
		/*for (int i = 0; i < sl;i++)
		{
			cout << "(" << toa_do_x[i] << "," << toa_do_y[i] << ")" << endl;
			
		}
		cout << "(" << xqua << "," << yqua << ")" << endl;
		
		cout << kt_huong();
		system("pause");*/
		int huong = kt_huong();
		check = huong;
		//check = 3;
		ve_qua();
		diem++;
	}
	if (diem > diem_cao)
	{
		diem_cao = diem;
	}
}

void thong_bao()
{
	bool kt_menu2 = true;
	if (game_over())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";	
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play1();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao2()
{
	bool kt_menu2 = true;
	if (game_over2())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play2();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao3()
{
	bool kt_menu2 = true;
	if (game_over3())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "PLAYER 1 SCORE: " << diem;
		gotoXY(55, 12);
		cout << "PLAYER 2 SCORE: " << diem2;
		gotoXY(55, 14);
		if (kt_ran_cham_ran() == 1 || ((toa_do_x[0] == 10 || toa_do_x[0] == 110 || toa_do_y[0] == 1 || toa_do_y[0] == 27) && diem>diem2))
			cout << "*** PLAYER 2 IS WINNER ***";
		else if (kt_ran_cham_ran() == 2|| ((toa_do_x2[0] == 10 || toa_do_x2[0] == 110 || toa_do_y2[0] == 1 || toa_do_y2[0] == 27) && diem2 > diem))
			cout << "*** PLAYER 1 IS WINNER ***";
		else if (diem > diem2) 
			cout << "*** PLAYER 1 IS WINNER ***";
		else if (diem < diem2) 
			cout << "*** PLAYER 2 IS WINNER ***";
		else 
			cout << "*** DRAW ***";
		gotoXY(55, 16);
		cout << "1. New Game";
		gotoXY(55, 17);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 18);
		cout << "Your choice: ";
		cin >> choice;
		diem2 = 0;
		diem = 0;
		sl = 4;
		sl2 = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play3();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao4()
{
	bool kt_menu2 = true;
	if (game_over())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play4();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao5()
{
	bool kt_menu2 = true;
	if (game_over())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		sl2 = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play5();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao6()
{
	bool kt_menu2 = true;
	if (game_over())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		sl2 = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play6();
		case 0:
			system("cls");
			menu();
		}
	}
}

void thong_bao7()
{
	bool kt_menu2 = true;
	if (game_over())
	{
		system("cls");
		gotoXY(55, 10);
		cout << "GAME OVER";
		gotoXY(55, 11);
		cout << "SCORE: " << diem;
		gotoXY(55, 12);
		cout << "MAX SCORE: " << diem_cao;
		gotoXY(55, 14);
		cout << "1. New Game";
		gotoXY(55, 15);
		cout << "0. Exit to Menu" << endl;
		int choice = 0;
		gotoXY(55, 16);
		cout << "Your choice: ";
		cin >> choice;
		diem = 0;
		sl = 4;
		switch (choice)
		{
		case 1:
			system("cls");
			play7();
		case 0:
			system("cls");
			menu();
		}
	}
}