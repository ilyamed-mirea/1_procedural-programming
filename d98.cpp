#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int d98() {
	bool fl = true;
	int n, k, P;
	while (fl) {
		fl = false;
		cout << "98) write n(colvo stypenek), k(colvo orehov) and P(prochnost)" << endl;
		n = getInt();
		k = getInt();
		P = getInt();
		if (n <= 0 || k <= 0 || P<=0) {
			cout << "n <= 0 or k <= 0. try again" << endl;
			fl = true;
		}
	}
	if (n == 1) {
		cout << "ans: 1" << endl;
	}
	else if (n < P) {
		cout << "oreh ne razobjetsa. n<P" << endl;
	}
	else {
		int start = 0, end = n, center = 0, ans = 0;

		while (center != P) {
			center = (start + end + 1) / 2; // Поиск середины
			if (P > center)
			{
				start = center;
			}
			else if (P < center)
			{
				end = center;
			}
			else
			{
				break;
			}
			ans += 1;
		}
		if (ans > k) {
			cout << "malo orehov" << endl;
		}
		else {
			cout << "minimum colvo popitok: " << ans << endl;
		}
	}

	return 0;
}