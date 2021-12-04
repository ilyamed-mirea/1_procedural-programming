#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

int spin() {
	cout << "spinners" << endl;
	cout << "write a,b,c (price base, price lopasti, max price)" << endl;
	int a = getInt();
	int b = getInt();
	int c = getInt();
	cout << (c - a) / b << endl;


	return 0;
}