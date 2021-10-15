#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Windows.h>
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
	cout << "1) print n1 and n2" << endl;
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

	//3
	string alp = "0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ";
	cout << "32) print sdvig:" << endl;
	n = getInt();
	cout << "print string: " << endl;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {

	}

	//fix 3.1 + 3.4 + 3.5 + 4.3 + 4.6
	return 0;
}