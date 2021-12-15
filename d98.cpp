#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int d98() {
	cout << "98) write n,k" << endl;
	int n = getInt(), k = getInt();
	bool fl = true;
	int p = ceil(n / 2);
	while (fl) {
		p = ceil(p / 2);
	}

	return 0;
}