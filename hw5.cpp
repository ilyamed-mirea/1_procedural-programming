#include <iostream>
#include <fstream>  
#include "Header.h"
#include <string>
using namespace std;

void erat(int n) {
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = i;
	for (int p = 2; p < n + 1; p++)
	{
		if (a[p] != 0)
		{
			cout << a[p] << endl;
			for (int j = p * p; j < n + 1; j += p)
				a[j] = 0;
		}
	}
	/*
	int c = 0;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			c += 1;
			break;
		}
	}
	if (c == 0) {
		return true;
	}
	else {
		return false;
	}
	*/
}

int hw5() {
	//1
	cout << "1) write n1 and n2" << endl;
	int n1 = getInt();
	int n2 = getInt();
	int x1 = n1;
	int x2 = n2;
	while (n1 != 0 && n2 != 0) {
		if (n1 > n2) {
			n1 = n1 % n2;
		}
		else {
			n2 = n2 % n1;
		}
	}
	cout << "del: " << n1 + n2 << endl;
	while (x1 != x2) {
		if (x1 > x2) {
			x1 -= x2;
		}
		else {
			x2 -= x1;
		}
	}
	cout << "minus: " << x2 << endl;

	//2
	cout << "2) print n: " << endl;
	int n = getInt();
	erat(n);

	//3.1 files
	//запись начальной строки в файл
	string str;
	ofstream f311("h5_1.txt");
	cout << "3.1) write razdel:" << endl;
	char razd;
	cin >> razd;
	cout << "write string: " << endl;
	getline(cin, str, '\n'); //heatup
	getline(cin, str, '\n');
	f311 << str;
	f311.close();

	//редактирование строки в файле
	str = "";
	ifstream f312("h5_1.txt");
	while (!f312.eof()) {
		str += f312.get();
	}
	f312.close();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str[i] = razd;
		}
	}
	ofstream clear("h5_1.txt", ofstream::out | ofstream::trunc);
	clear.close();
	ofstream f3122("h5_1.txt");
	for (int i = 0; i < str.length(); i++) {
		f3122 << str[i];
	}
	f3122.close();

	//вывод файла
	str = "";
	ifstream f313("h5_1.txt");
	while (!f313.eof()) {
		str += f313.get();
	}
	f313.close();
	cout << str << endl;

	remove("h5_1.txt");

	//3.32 files
	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ofstream f321("h5_2.txt");
	int alplen = alp.length();
	cout << "3.32) write sdvig:" << endl;
	n = getInt();
	cout << "write string (in english): " << endl;
	getline(cin, str, '\n'); //heatup
	getline(cin, str, '\n');

	//запись в файл
	f321 << str; 
	str = "";
	f321.close();

	//редактирование строки в файле
	ifstream f322("h5_2.txt");
	while (!f322.eof()) {
		str += f322.get(); //чтение из файла
	}
	ofstream clear2("h5_2.txt", ofstream::out | ofstream::trunc);
	clear2.close();
	ofstream f323("h5_2.txt");
	for (int i = 0; i < str.length(); i++) {
			char temp = str[i];
			for (int j = 0; j < alplen; j++) {
				if (alp[j] == str[i]) {
					int sum = j + n;
					if (sum > alplen) {
						while (sum > alplen) {
							sum -= alplen;
						}
					}
					str[i] = alp[sum];
					break;
				}
				else if (tolower(alp[j]) == str[i]) {
					int sum = j + n;
					if (sum > alplen) {
						while (sum > alplen) {
							sum -= alplen;
						}
					}
					str[i] = tolower(alp[sum]);
					break;
				}
			}
	}
	f323 << str;
	f323.close();

	//чтение из файла
	str = "";
	ifstream f324("h5_2.txt");
	while (!f324.eof()) {
		str += f324.get();
	}
	f324.close();
	cout << "coded: " << str << endl;
	remove("h5_2.txt");

	return 0;
}