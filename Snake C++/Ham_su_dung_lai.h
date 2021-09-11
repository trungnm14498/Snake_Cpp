#pragma once
#include <iostream>
using namespace std;
// Bien toan cuc
#define MAX 100
int toa_do_x[MAX] = { 0 };
int toa_do_y[MAX] = { 0 };
int toa_do_x2[MAX] = { 0 };
int toa_do_y2[MAX] = { 0 };
int sl = 4;
int sl2 = 4;
int xqua = -1;
int yqua = -1;
int diem = 0;
int diem2 = 0;
int speed = 0;
int speed2 = 0;
int diem_cao = 0;

void tao_ran()
{
	int x = 16, y = 2;
	for (int i = 0;i < sl;i++)
	{
		toa_do_x[i] = x--;
		toa_do_y[i] = y;
	}
}

void ve_ran(int z, int a[], int b[], int soluong)
{
	gotoXY(a[0], b[0]);
	cout << char(z);
	for (int i = 1; i < soluong; i++)
	{
		gotoXY(a[i], b[i]);
		cout << "o";
	}
}

void ve_ran_mau(int z, int a[], int b[], int soluong, int i)
{	
	SetColor(i);
	gotoXY(a[0], b[0]);
	cout << char(z);
	for (int i = 1; i < soluong; i++)
	{
		gotoXY(a[i], b[i]);
		cout << "o";
	}
}

void di_chuyen_ran(int x, int y, int a[], int b[], int soluong)
{
	for (int i = soluong; i > 0; i--)
	{
		a[i] = a[i - 1];
		b[i] = b[i - 1];
	}
	a[0] = x;
	b[0] = y;
}

bool kt_ran_cham_than(int soluong, int a[], int b[])
{
	for (int i = 1;i < soluong;i++)
	{
		if (a[0] == a[i] && b[0] == b[i])
		{
			return true;
		}
	}
	return false;
}

bool kt_ran_va_qua()
{
	for (int i = 0; i < sl; i++)
	{
		if (toa_do_x[i] == xqua && toa_do_y[i] == yqua) {
			return true;
		}
	}
	for (int i = 0; i < sl2; i++)
	{
		if (toa_do_x2[i] == xqua && toa_do_y2[i] == yqua) {
			return true;
		}
	}
	return false;
}

void ve_qua()
{
	gotoXY(xqua, yqua);
	cout << char(15);
}

void ve_qua_mau(int i)
{
	SetColor(i);
	gotoXY(xqua, yqua);	
	cout << char(15);
}

int kt_ran_an_qua()
{
	if (toa_do_x[0] == xqua && toa_do_y[0] == yqua)
	{
		return 1;
	}
	if (toa_do_x2[0] == xqua && toa_do_y2[0] == yqua)
	{
		return 2;
	}
	return 0;
}

int toc_do(int &speed)
{
	int lvl = diem / 10;
	if (lvl == 0)
	{
		speed = 100;
	}
	else if (lvl == 1)
	{
		speed = 75;
	}
	else if (lvl == 2)
	{
		speed = 50;
	}
	else if (lvl >= 3)
	{
		speed = 25;
	}
	return speed;
}

void doi_mau()
{
	int lvl = diem / 10;
	if (lvl == 1)
	{
		SetColor(11);
	}
	else if (lvl == 2)
	{
		SetColor(13);
	}
	else if (lvl == 3)
	{
		SetColor(12);
	}
}