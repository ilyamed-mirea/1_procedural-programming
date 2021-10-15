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
	cout << "print a,b" << endl;
	int a = getInt();
	int b = getInt();
	if (a > 0 && b > 0) {
		cout << "S: " << a * b << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}
void triangle() {
	cout << "print a,h" << endl;
	int a = getInt();
	int h = getInt();
	if (a>0 && h>0) {
		cout << "S: " << 0.5 * a * h << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}
void round() {
	cout << "print r" << endl;
	int r = getInt();
	if (r>0) {
		cout << "S: " << M_PI * pow(r,2) << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}

string ConvertCC(string a, int from, int to) {
	string abc = "0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ";
	string buf, result = "";
	int i, k = 0;
	int ten = 0; //in dec cc
	int stp = 1; //stepen
	 
	//perevod v 10
	for (i=a.length()-1; i>-1; i--) {
		k = 0;
		while (abc[k] != a[i] && k < 36) {
			k++; //viasnit poradkoviy nomer
		}
		ten += k * stp; //send to ten
		stp *= from; //stepen update for next
	}
	
	//reverse formula
	while (ten) {
		i = ten % to; //get num in CC
		buf+= abc[i]; //save to buffer
		ten /= to;
	}

	//reverse buffer to result
	for (i = buf.length()-1; i > -1; i--) {
		result+= buf[i];
	}

	return result;
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
	int s1 = 0;
	while (f12 >> x) {	//(!f2.eof()) {
		s1 += x;
	}
	cout << "sum: " << s1 << endl;
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
	

	//6
	cout << "6) write roman number" << endl;
	char lat[100];
	int count = 0;

	cin.getline(lat, 100);
	cin.getline(lat, 100);
	//povtor 
	int chk = 0;
	for (int i = 0; i < strlen(lat); i++) {
		//
		chk = 0;
		if (lat[i] == 'I') {
			int x = i;
			while (lat[x] == 'I') {
				x += 1;
				chk += 1;
			}
			if (chk >= 4 || (lat[i+1]=='L'|| lat[i + 1] == 'C' || lat[i + 1] == 'D' || lat[i + 1] == 'M')) {
				count += 1;
				break;
			}
			else {
				chk = 0;
			}
		}
		if (lat[i] == 'V') {
			int x = i;
			while (lat[x] == 'V') {
				x += 1;
				chk += 1;
			}
			if (chk >= 2) {
				count += 1;
				break;
			}
			else {
				chk = 0;
			}
		}
		if (lat[i] == 'X') {
			int x = i;
			while (lat[x] == 'X') {
				x += 1;
				chk += 1;
			}
			if (chk >= 4) {
				count += 1;
				break;
			}
			else {
				chk = 0;
			}
		}
		if (lat[i] == 'L') {
			if (lat[i+1] == 'L') {
				count += 1;
				break;
			}
		}
		if (lat[i] == 'C') {
			int x = i;
			while (lat[x] == 'C') {
				x += 1;
				chk += 1;
			}
			if (chk >= 4) {
				count += 1;
				break;
			}
			else {
				chk = 0;
			}
		}
		if (lat[i] == 'D') {
			if (lat[i + 1] == 'D') {
				count += 1;
				break;
			}
		}




		//pr на 4 I подряд
	}
	if (count == 0) {
		for (int i = 0; i < strlen(lat); i++) {
			switch (lat[i]) {
			case 'M':
				count += 1000;
				break;
			case 'D':
				count += 500;
				break;
			case 'C':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'D' || lat[i + 1] == 'M'))
					count -= 100;
				else
					count += 100;
				break;
			case 'L':
				count += 50;
				break;
			case 'X':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'L' || lat[i + 1] == 'C' || lat[i + 1] == 'M'))
					count -= 10;
				else
					count += 10;
				break;
			case 'V':
				count += 5;
				break;
			case 'I':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'V' || lat[i + 1] == 'X' || lat[i + 1] == 'C'))
					count -= 1;
				else count += 1;
				break;
			}
		}
	}
	else {
		cout << "error. invalid number" << endl;
	}
	cout << "decoded: " << count << endl;

	//7
	cout << "7) write m,i,c" << endl;
	double m, i, c, s, slast;
	m = getDouble();
	i = getDouble();
	c = getDouble();
	slast = 0.0;
	s = 0.0;
	for (int k = 0; k < 5; k++) {
		s = fmod((m * slast + i), c);
		cout << s << endl;
		slast = s;
	}
	//8
	cout << "8) " << endl;
	int ma[3][4] = { {5,2,0,10}, {3,5,2,5}, {20,0,0,0} };
	double mb[4][2] = { {1.20, 0.50}, {2.80,0.40}, {5.00,1.00}, {2.00,1.50} };
	double mc[3][2];
	
	/*
	//cin maxtrix
	cout << "write ma:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "write " << i+1 << ' ' << j+1 << " element: ";
			int a = getInt();
			ma[i][j] = a;
		}
	}
	cout << "write mb:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "write " << i+1 << ' ' << j+1 << " element: ";
			double a = getDouble();
			mb[i][j] = a;
		}
	}
	//cout matrix
	cout << "ma:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ma[i][j] << " ";
		}
		cout << endl;
	}
	cout << "mb:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cout << mb[i][j] << " ";
		}
		cout << endl;
	}
	*/

	//calc mc
	double res = 0;
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < 3; i++) {
		for (int iB = 0; iB < 2; iB++) {
			res = 0;
			for (int j = 0; j < 4; j++) { //stolb a = stroke b
				//cout << ma[i][j] << " " << mb[j][iB] << endl;
				res += ma[i][j] * mb[j][iB];
			}
			mc[c1][c2] = res;
			c2 += 1;
		}
		c1 += 1;
		c2 = 0;
	}

	//cout mc
	cout << "mc:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << mc[i][j] << "    ";
		}
		cout << endl;
	}

	//8.1
	int prodMax = 0;
	int prodMin = 0;
	double maxcom = 0;
	double mincom = 10000;
	for (int i = 0; i < 3; i++) {
		//cout << mc[i][1] << endl;
		if ((mc[i][1]+mc[i][0]) > maxcom) {
			maxcom = (mc[i][1] + mc[i][0]);
			prodMax = i + 1;
		}
		if ((mc[i][1] + mc[i][0]) < mincom) {
			mincom = (mc[i][1] + mc[i][0]);
			prodMin = i + 1;
		}
	}
	cout << "max sum: " << prodMax << endl;
	cout << "min sum: " << prodMin << endl;

	//8.2
	prodMax = 0; prodMin = 0; maxcom = 0; mincom = 100000;
	for (int i = 0; i < 3; i++) {
		//cout << mc[i][1] << endl;
		if (mc[i][1] > maxcom) {
			maxcom = mc[i][1];
			prodMax = i+1;
		}
		if (mc[i][1] < mincom) {
			mincom = mc[i][1];
			prodMin = i + 1;
		}
	}
	cout << "max commission: " << prodMax << endl;
	cout << "min commission: " << prodMin << endl;

	//8.3
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][0];
	}
	cout << "all products sum: " << res << endl;

	//8.4
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][1];
	}
	cout << "all commission sum: " << res << endl;

	//8.5
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][1] + mc[i][0];
	}
	cout << "all money: " << res << endl;

	//9
	cout << "9) " << endl;
	string num,ans;
	int oldBase,newBase = 0;
	cout << "write num" << endl;
	cin >> num;
	cout << "write old base" << endl;
	oldBase = getInt();
	cout << "write new base" << endl;
	newBase = getInt();

	ans = ConvertCC(num, oldBase, newBase);
	cout << ans << endl;

	
	return 0;
}