#include <iostream>
#include <string>
#include <set>
#include "Header.h"
using namespace std;

long long pop(multiset<long long>& s)
{
	auto it = s.end();
	--it;
	int ans = *it;
	s.erase(it);
	return ans;
}

int section(int k) {
	if (k <= 36)
		return (k - 1) / 4;
	else
		return 8 - ((k - 37) / 2);
}

int spin() {
	cout << "spinners" << " 1)" << endl;
	bool fl = true;
	double a, b, c;
	while (fl) {
		fl = false;
		cout << "write a,b,c (price base, price lopasti, max price)" << endl;
		a = getDouble();
		b = getDouble();
		c = getDouble();
		if (a > c) {
			cout << "error. try again" << endl;
			fl = true;
		}
	}
	cout << "ans: " << int((c - a) / b) << endl;

	cout << "2) " << endl << "write m " << endl;
	double m = getDouble();
	double n4 = int(m) % 3;
	double n3 = (m - 4 * n4) / 3;
	if (n3 >= 0) {
		cout << n3 << endl << n4 << endl;
	}
	else {
		cout << 0 << endl << 0 << endl;
	}

	cout << "3) " << endl << "write n,m" << endl;
	int n,m2;
	m2 = getInt();
	n = getInt();
	double ans_x = 0;
	double ans_y = 0;
	for (int x = 0; x < n; x++) {
		ans_x += n - x;
	}
	for (int y = 0; y < m2; y++) {
		ans_y += m2 - y;
	}
	cout << ans_x*ans_y << endl;

	cout << "4) " << endl << "write n" << endl;
	int count[9] = { 0 };
	n = getInt();
	cout << "write numbers of free places" << endl;
	for (int i = 0; i < n; i++) {
		int f;
		f = getInt();
		count[section(f)]+=1;
	}
	int ans = 0;
	int curr = 0;
	//for (int i = 0; i < 9; i++) cout << count[i] << endl;
	for (int i = 0; i < 9; i++) {
		if (count[i] == 6) {
			curr += 1;
			ans = max(ans, curr); //ans >= curr ? ans : curr;
		}
		else {
			curr = 0;
		}
	}
	cout << "ans: " << ans << endl;

	cout << "5) ";
	long long n2, k;
	fl = true;
	while (fl) {
		fl = false;
		cout << endl << "write n,k" << endl;
		cin >> n2 >> k;
		if (k>n2) {
			cout << "error.try again";
			fl = true;
		}
	}
	multiset<long long> s;
	s.insert(n2);
	long long ans1, ans2 = 0;
	for (long long i = 0; i < k; ++i)
	{
		n2 = pop(s);
		ans1 = (n2 - 1) / 2;
		ans2 = n2 - 1 - ans1;
		s.insert(ans1);
		s.insert(ans2);
	}
	cout << ans1 << endl;
	cout << ans2 << endl;



	return 0;
}