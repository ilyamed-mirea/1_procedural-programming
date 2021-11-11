#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>


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
	if (S <= 0 || p < 0 || n <= 0) {
		cout << "error. try again." << endl;
		hw3();
	}
	if (p == 0) {
		cout << S/(n*12) << endl;
	}
	else if (12 * (x - 1) > 0) {
		m = (S * r * x) / (12 * (x - 1));
		cout << "ans: " << m << endl;
	}
	else {
		cout << "error. m < 0, try again" << endl;
		hw3();
	}

	//2
	cout << "2) write S, m, n" << endl;
	S = getDouble();
	m = getDouble();
	n = getDouble();
	if (S <= 0 || m <= 0 || n <= 0) {
		cout << "error. try again." << endl;
		hw3();
	}
	double m2 = m - 1;
	//double pp = 123.456789;
	//cout << round(pp*1000)/1000 << endl;
	p = 0;
	double r2;

	while (m>m2) {
		p += 0.1;
		r2 = p / 100;
		m2 = (S * r2 * pow((1 + r2), n)) / (12*((pow(1 + r2, n))-1));
	}
	p-=0.1;
	cout << "p: " << p << "%" << endl;
	
	//3
	cout << "3) write text in file" << endl;
	ofstream f31;
	ifstream f32;
	string text;

	f31.open("hw3_copy.txt");
	
	//cin >> text;
	getline(cin, text); //разогрев
	getline(cin, text, '\n');
	//text = "hi from 3_3";

	if (f31.is_open())	{
		f31 << text;
		f31.close();
	}

	f32.open("hw3_copy.txt");
	if (f32.is_open()) {
		while (!f32.eof()) {
			f32 >> text;
			cout << text << " ";
		}
		cout << endl;
		f32.close();
	}

	//4
	cout << "4) write numbers in file to filter" << endl;
	ofstream f41;
	ifstream f42;
	f41.open("hw3_filter.txt");
	char ch1,ch2;

	getline(cin, text, '\n');
	//text = "ab2cgh345 6 7 c8";
	//text = "easy: abc1vb2b3b4n567 8       9               10\nmedium: -2 1-3 4--5 -6-7------------8 ---------+0 --99--\nhard: 1.2 33.44 5,6 7..8 7. 8. .7 .8 -910.1112 1.-2";
	//easy: 1 2 3 4 567 8 9 10
	//medium: -2 1 -3 4 -5 -6 -7 -8 0 -99
	//hard: 1.2 33.44 5 6 -910.1112
	if (f41.is_open()) {
		f41 << text;
		f41.close();
	}
	int fl = 0;
	f42.open("hw3_filter.txt");
	if (f42.is_open()) {
		while (!f42.eof()) {
			fl==1?fl=0:ch1 = f42.get();
			if ((isdigit(ch1) != 0) || (ch1=='-')) { //если 1 число или минус
				ch2 = f42.get(); //берем второе
				if ((isdigit(ch1) != 0) && (ch2 == '.')) { //если 1 число И 2 точка
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
				else if (ch1 == '-') { //если 1 минус
					if (isdigit(ch2) != 0) { //если второе число
						cout << ch1 << ch2;
						ch1 = f42.get();
						fl = 1;
						while (isdigit(ch1) != 0) {
							cout << ch1;
							ch2 = ch1;
							ch1 = f42.get();
						}
						if ((isdigit(ch2) != 0) && (ch1 == '.')) { //если много чисел и точка, вывод точки и всех чисел после точки
							cout << ch1;
							ch1 = f42.get();
							while (isdigit(ch1) != 0) {
								cout << ch1;
								ch1 = f42.get();
							}
						}
						
						cout << endl;
					}
					else { //перезапись первого на второе с флажком, что бы с него продолжить
						fl = 1;
						ch1 = ch2;
					}
				}
				else if (isdigit(ch1) != 0) { //просто вывод чисел
					cout << ch1;
					ch1 = ch2;
					fl = 1;
					while (isdigit(ch1) != 0) {
						cout << ch1;
						ch2 = ch1; //save if . next
						ch1 = f42.get();
					}
					if ((isdigit(ch2)!=0) && (ch1 == '.')) { //если много чисел и точка, вывод точки и всех чисел после точки
						cout << ch1;
						ch1 = f42.get();
							while (isdigit(ch1) != 0) {
								cout << ch1;
								ch1 = f42.get();
							}
					}
					cout << endl;
				}
				else {
					cout << endl;
				}
			}
		}
		f42.close();
	}

	//5
	cout << "5) write string to sort" << endl; //ввод с клав! всего файла
	ofstream f51;
	ifstream f52;
	f51.open("hw3_sort.txt");
	
	getline(cin, text, '\n');
	//text = "rstuvwxyzabcdefghijklmnopqbaqw";

	if (f51.is_open()) {
		f51 << text;
		f51.close();
	}


	f52.open("hw3_sort.txt");
	if (f52.is_open()) {
		text = "";
		while (!f52.eof()) {
			text += f52.get();
		}
		f52.close();
	}

	fl = 0;
	while (fl == 0) {
		fl = 1;
		for (int i = 0; i < text.length(); i++) {
			for (int j = i + 1; j < text.length()-1; j++) {
				if (text[i] > text[j]) {
					fl = 0;
					char temp = text[i];
					text[i] = text[j];
					text[j] = temp;
				}
			}
		}
	}
	cout << text << endl;

	//deleting files
	remove("hw3_copy.txt");
	remove("hw3_filter.txt");
	remove("hw3_sort.txt");
	return 0;
}	