//hw6.cpp
	// 2 ryad + 1 file + 1 structurnchisla
#include <iostream>
#include <fstream>  
#include "Header.h"
#include <string>
using namespace std;

string convert(string num, int to) {
	string abc = "0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ";
	string buf, result = "";
	int i, k = 0;
	int ten = 0; //in dec cc
	int stp = 1; //stepen

	//perevod v 10
	for (i = num.length() - 1; i > -1; i--) {
		k = 0;
		while (abc[k] != num[i] && k < 36) {
			k++; //viasnit poradkoviy nomer
		}
		ten += k * stp; //send to ten
		stp *= 16; //stepen update for next
	}

	//reverse formula
	while (ten) {
		i = ten % to; //get num in CC
		buf += abc[i]; //save to buffer
		ten /= to;
	}

	//reverse buffer to result
	for (i = buf.length() - 1; i > -1; i--) {
		result += buf[i];
	}

	return result;
}

int hw6() {
	//4.16 ryad
	cout << "4.16)" << endl;
	cout << "write e: " << endl;
	double e = getDouble();
	double y = 0;
	double n = 1;
	double mn = 1 / (pow(3, n));
	int incos = pow(3, n - 1);
	while (mn>=e) {
		y += mn * pow(cos(incos), 3);
		//cout << mn << " and " << e << " XXX" << incos << " " << (1 / (pow(3, n))) * pow(cos(incos), 3) << endl;
		n++;
		mn = 1 / (pow(3, n));
		incos = pow(3, n - 1);
	}
	cout << "y = " << y << endl;
	system("pause");

	//4.14 ryad
	cout << "4.14)" << endl;
	for (int i = 1000; i <= 9999; i++) {
		string num = to_string(i);
		int fl = 0;
		for (int j = 0; j < num.length(); j++) {
			for (int k = j + 1; k < num.length(); k++) {
				if (num[j] == num[k]) {
					fl = 1;
					break;
				}
			}
			if (fl == 1) {
				break;
			}
		}
		if (fl == 0) {
			cout << i << endl;
		}
	}

	//file
	cout << "5.16) " << endl << "to system: ";
	int to = getInt();
	if (to > 9 || to < 2) {
		cout << "error. only 2 - 9 systems. try again" << endl;
		exit(0);
	}
	
	string str = "24 3C 6BCA24A";
	cout << "numbers in 16 system: " << str << endl;
	//getline(cin, str, '\n');
	ofstream f61("h6_1code.txt");
	f61 << str;
	f61.close();
	str = "";

	ifstream f62("h6_1code.txt");
	while (!f62.eof()) {
		char x = f62.get();
		str += x;
	}
	f62.close();
	string res, num = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || i == str.length()-1) {
			string temp = convert(num, to);
			res += temp + " ";
			cout << num << ": " << temp << endl;
			num = "";
		}
		else {
			num += str[i];
		}
	}
	ofstream f63("h6_1decode.txt");
	f63 << res;
	f63.close();
	system("pause");
	remove("h6_1code.txt");
	remove("h6_1decode.txt");

	//chisla
	cout << "amorf. print m,n: " << endl;
	int a = getInt();
	int b = getInt();
	cout << "===============================" << endl;
	for (int i = a; i <= b; i++) {
		string o = to_string(i);
		string p = to_string(i * i);
		if (p.substr(p.length() - o.length())==o) {
			cout << i << " " << p << endl;
		}

	}

	return 0;
}