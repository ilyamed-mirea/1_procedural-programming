#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int getRand() {
	int r = (rand() * rand()) % 10000;
	bool fl = true;
	while (fl) {
		r++;
		if (r > 9999) {
			r -= (rand() * rand()) % 1000;
		}
		fl = false;
		string nr = to_string(r);
		for (int i = 0; i < nr.length()-1; i++) {
			for (int j = i + 1; j < nr.length(); j++) {
				if (nr[i] == nr[j]) {
					fl = true;
				}
			}
		}

	}

	return r;
}

int d99() {
	cout << "99) " << endl;
	int randm = getRand();
	string nrandm = to_string(randm);
	cout << randm << endl;


	int n = 0;
	while (n != randm) {
		int plus = 0;
		int minus = 0;
		cout << "write num" << endl;
		n = getInt();
		string ns = to_string(n);
		if (ns.length() != 4) {
			cout << "error.try again" << endl;
		}
		else {
			for (int i = 0; i < ns.length(); i++) {
				if (ns[i] == nrandm[i]) {
					plus++;
				}
				else {
					minus++;
				}
			}
		}
		cout << "plus: " << plus << endl << "minus: " << minus << endl;
	}
	cout << "congrats!" << endl;


	return 0;
}