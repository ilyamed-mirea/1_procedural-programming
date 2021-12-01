#include <iostream>
#include <cmath>
#include "Header.h"
#include <string>
using namespace std;

bool isPrime(int x) {
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
	for (int i = 2; i < n; i++) {
		if (isPrime(i)) {
			cout << i << endl;
		}
	}

	//3.32 files
	string alp = "ABCDEFGHIJKLMNOPQRESTUVWXYZ";
	int alplen = alp.length();
	//string nums = "0123456789";
	cout << "3.32) write sdvig:" << endl;
	n = getInt();
	cout << "write string (in english): " << endl;
	string str;
	getline(cin, str, '\n'); //heatup
	getline(cin, str, '\n');

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
	cout << "coded: " << str << endl;


	return 0;
}