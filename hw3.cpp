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
	double S, p, n, m, r, x = 0;
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
	cout << "3) write text in file" << endl; //create + ввод с клавиатуры
	ofstream f31;
	ifstream f32;
	string text;

	f31.open("hw3_copy.txt");//, fstream::in | fstream::out); 
	
	//cin >> text;
	text = "hi from 3_3";

	if (f31.is_open())	{
		f31 << text;
		f31.close();
	}

	f32.open("hw3_copy.txt");
	if (f32.is_open()) {
		while (!f32.eof()) {
			f32 >> text;
			cout << text << " "; //вывод
		}
		cout << endl;
		f32.close();
	}
	

	//4
	cout << "4) write numbers in file " << endl; //ввод с клав! всего файла
	ofstream f41;
	ifstream f42;
	f41.open("hw3_filter.txt");
	char ch1,ch2;

	//cin >> text;
	text = "1 -1 +1 2.5 -2.5 +2.5 +-+-2.5 .2 2. 2..2";

	if (f41.is_open()) {
		f41 << text;
		f41.close();
	}
	int fl = 0;
	f42.open("hw3_filter.txt");
	//2. и .2 нет
	if (f42.is_open()) {
		while (!f42.eof()) {
			fl==1?fl=0:ch1 = f42.get();
			if ((isdigit(ch1) != 0) || (ch1=='-')) {
				ch2 = f42.get();
				if ((isdigit(ch1) != 0) && (ch2 == '.')) {
					char temp = ch1;
					ch1 = f42.get();
					fl = 1;
					if (isdigit(ch1) != 0) {
						cout << temp << ch2;
						while (isdigit(ch1) != 0) {
							cout << ch1;
							ch1 = f42.get();
						}
						cout << endl;
					}
				}
				else if (ch1 == '-') {
					if (isdigit(ch2) != 0) {
						cout << ch1 << ch2;
						ch1 = f42.get();
						fl = 1;
						while (isdigit(ch1) != 0) {
							cout << ch1;
							ch1 = f42.get();
							if () //proverka na tocku!!!!!
						}
						cout << endl;
					}
				}
				else if (isdigit(ch2) != 0) {
					cout << ch1 << ch2;
				}
				else if (isdigit(ch2) == 0) {
					cout << ch1 << endl;
				}
				else {
					cout << endl;
				}
			}
			/*else if ((ch1 == '-' || ch1 == '+')){// &&  isdigit(ch2)!=0) {
				cout << endl << ch1;
			}*/
		}
		f42.close();
	}

	//5
	cout << "5) " << endl; //ввод с клав! всего файла
	ofstream f51;
	ifstream f52;
	f51.open("hw3_sort.txt");
	
	//cin>>text;
	text = "rstuvwxyzabcdefghijklmnopqbaqw";
	if (f51.is_open()) {
		f51 << text;
	}

	f52.open("hw3_sort.txt");
	if (f52.is_open()) {
		while (!f52.eof()) {
			text += f52.get();
		}
		f52.close();
	}
	sort(text.begin(), text.end()); //bettersort
	cout << text << endl;

	return 0;
}	