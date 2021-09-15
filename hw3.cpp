#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>
#include <algorithm>

using namespace std;

int hw3() {
	cout << "hw3" << endl;
	//1
	double S, p, n, m, r, x;
	cout << "1) write S, p, n" << endl;
	S = getDouble();
	p = getDouble();
	n = getDouble();
	r = p / 100;
	x = pow((1 + r), n);
	if (S <= 0 || p <= 0 || n <= 0) {
		cout << "error. try again." << endl;
		hw3();
	}
	if (12 * (x - 1) != 0) {
		m = (S * r * x) / (12 * (x - 1));
		cout << "ans: " << m << endl;
	}
	else {
		cout << "error. m < 0, try again" << endl;
		hw3();
	}
	cout << r << endl;
	//2
	cout << "2) " << endl;
	double r2 = 0.001;
	while (true) {
		x = pow((1 + r2), n);
		//if ((pow(1 + r2, n) == ((12 * m) / (12 * m - (S * r2)))) && r2==r) {
		//cout << ((S * r2 * pow((1 + r2), n)) == (m * 12 * (pow((1 + r2), n) - 1))) << endl;
		if (((S * r2 * x) == (m * 12 * (x - 1))) && r2 == r) { //why not working
			cout << "p: " << 100 * r2 << endl;
			break;
		}
		if (r2 > 1) {
			cout << ". error" << endl;
			break;
		}
		r2 += 0.001;
	}
	
	//3
	cout << "3) " << endl; //create + ввод с клавиатуры
	fstream file;
	string text;

	file.open("hw3_copy.txt", fstream::in | fstream::out); 

	if (file.is_open())	{
		while (!file.eof())	{
			file >> text;
			cout << text << " "; //вывод
		}
		cout << endl;
		file.close();
	}
	

	//4
	cout << "4) " << endl; //ввод с клав! всего файла
	ifstream f2;
	f2.open("hw3_filter.txt");
	char ch;
	if (f2.is_open()) {
		while (!f2.eof()) {
			ch = f2.get();
			if (isdigit(ch) != 0) {
				cout << ch << endl;
			}

		}
	}
	f2.close();

	//5
	cout << "5) " << endl; //ввод с клав! всего файла
	ifstream f3;
	f3.open("hw3_sort.txt");
	string s;
	if (f3.is_open()) {
		while (!f3.eof()) {
			s += f3.get();
		}
	}
	sort(s.begin(), s.end()); //bettersort
	cout << s << endl;
	f3.close();

	return 0;
}	