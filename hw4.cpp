#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>
#include <algorithm>

using namespace std;

string checkT(int x) {
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

int hw4() {
	cout << "hw4" << endl << "1)" << endl;
	//1
	ofstream f11("h4_1.txt");
	for (int i = 0; i < 10; i++) {
		cout << "write num: ";
		int x = getInt();
		f11 << x << endl;
	}
	f11.close();
	ifstream f12("h4_1.txt");
	int x;
	int s = 0;
	while (f12 >> x) {	//(!f2.eof()) {
		s += x;
	}
	cout << "sum: " << s << endl;
	f12.close();

	//2
	cout << "2) write number" << endl;
	x = getInt();
	cout << checkT(x) << endl;

	//3
	cout << "3) for rectangle print 1, for triangle print 2, for round print 3" << endl;
	x = getInt();
	if (x == 1) {
		rect();
	}
	else if (x == 2) {
		triangle();
	}
	else if (x == 3) {
		round();
	}
	else {
		cout << "error. try again" << endl;
		hw4();
	}

	//4
	cout << "4)" << endl;
	string str="";
	for (int i = 0; i < 13; i++) {
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

	return 0;
}