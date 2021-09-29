#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Windows.h>
using namespace std;

string checkT(double x) {
	if (x > 0) {
		return "num is positive";
	}
	else if (x == 0) {
		return "num is zero";
	}
	else if (x < 0) {
		return "num is negative";
	}
	else {
		return "error";
	}
}

void rect() {
	cout << "prin a,b" << endl;
	int a = getInt();
	int b = getInt();
	cout << "S: " << a * b << endl;
}
void triangle() {
	cout << "prin a,h" << endl;
	int a = getInt();
	int h = getInt();
	cout << "S: " << 0.5 * a * h << endl;
}
void round() {
	cout << "prin r" << endl;
	int r = getInt();
	cout << "S: " << M_PI * pow(r,2) << endl;
}
int roman(char x) {
	switch (x) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int hw4() {
	cout << "hw4" << endl << "1) write 10 numbers " << endl;
	//1
	ofstream f11("h4_1.txt");
	for (int i = 0; i < 10; i++) {
		cout << "write num " << i+1 << ": ";
		int x = getInt();
		f11 << x << endl;
	}
	f11.close();
	ifstream f12("h4_1.txt");
	int x;
	double x2;
	int s = 0;
	while (f12 >> x) {	//(!f2.eof()) {
		s += x;
	}
	cout << "sum: " << s << endl;
	f12.close();

	//2
	cout << "2) write number" << endl;
	x2 = getDouble();
	cout << checkT(x2) << endl;

	//3
	cout << "3) for rectangle print 1, for triangle print 2, for round print 3" << endl;
	x = getInt();
	switch (x) {
		case 1:
			rect();
			break;
		case 2:
			triangle();
			break;
		case 3:
			round();
			break;
		default:
			cout << "error. try again" << endl;
			hw4();
	}

	//4
	cout << "4)" << endl;
	string str="";
	for (int i = 0; i < 14; i++) {
		if (i < 8) {
			for (int j = 0; j < 6; j++) {
				str += " * ";
			}

			for (int j = 0; j < 24; j++) {
				str += "=";
			}
		}
		else {
			for (int j = 0; j < 42; j++) {
				str += "=";
			}
		}
		cout << str << endl;
		str = "";
	}
	//5
	system("pause");
	system("cls");
	cout << "5) y = sin(x)" << endl;
	//float x; now double
	int scale = 40;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	
	//MoveToEx(hDC, 0, 85, NULL);
	//LineTo(hDC, 200, 85); zero coord
	//MoveToEx(hDC, 100, 0, NULL);
	//LineTo(hDC, 100, 170); 

	//move(dc, y, x, null)
	MoveToEx(hDC, 0, 285, NULL);
	LineTo(hDC, 600, 285); //x
	MoveToEx(hDC, 300, 0, NULL);
	LineTo(hDC, 300, 600); //y

	for (x2 = -8.0f; x2 <= 8.0f; x2 += 0.01f) // O(300,285) - center
	{
		MoveToEx(hDC, scale * x2 + 300, -scale * sin(x2) + 285, NULL);
		LineTo(hDC, scale * x2 + 300, -scale * sin(x2) + 285);
	}
	/*
	system("pause");
	system("cls");
	//6
	cout << "6) write roman number" << endl;
	cin >> str;
	s = 0;
	//int s[9] = { 0 };
	char alp[7] = { 'I','V','X','L','C','D','M' };
	for (int i = 0; i < str.length(); i++) {
		cout << roman(str[i]);
	}
	cout << endl;//	 "decoded: " << s << endl;
	*/
	return 0;
}