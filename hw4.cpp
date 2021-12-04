#include <iostream>
#include <cmath>
#include <fstream>  
#include "Header.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <Windows.h>
using namespace std;

string checkT(double x) {
	if (x > 0) {
		return "num is positive";
	}
	else if (x == 0) {
		return "num is zero";
	}
	else if (x < 0) {
		return "num is negative";
	}
	return "error";
}

void rect() {
	cout << "write a,b" << endl;
	int a = getDouble();
	int b = getDouble();
	if (a >= 0 && b >= 0) {
		cout << "S: " << a * b << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}
void triangle() {
	cout << "write sides: a,b,c" << endl;
	double a = getDouble();
	double b = getDouble();
	double c = getDouble();
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		double p = (a + b + c) / 2; 
		double s = sqrt(p * (p - a) * (p - b) * (p - c));  
		cout << "S: " << s << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}
void round() {
	cout << "write r" << endl;
	int r = getDouble();
	if (r>=0) {
		cout << "S: " << 3.14 * pow(r,2) << endl;
	}
	else {
		cout << "doesnt exist" << endl;
	}
}


string ConvertCC1(string a, int from, int to) { //old
	string abc = "0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ";
	string buf, result = "";
	int i, k = 0;
	int ten = 0; //in dec cc
	int stp = 1; //stepen
	 
	//perevod v 10
	for (i=a.length()-1; i>-1; i--) {
		k = 0;
		while (abc[k] != a[i] && k < 36) {
			k++; //viasnit poradkoviy nomer
		}
		ten += k * stp; //send to ten
		stp *= from; //stepen update for next
	}
	
	//reverse formula
	while (ten) {
		i = ten % to; //get num in CC
		buf+= abc[i]; //save to buffer
		ten /= to;
	}

	//reverse buffer to result
	for (i = buf.length()-1; i > -1; i--) {
		result+= buf[i];
	}

	return result;
}
string ConvertCC2(string gotnum, int sys1, int sys2) { //new
	string a = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	string num, new_num, fraction, res;
	bool d = false;
	bool minus = false;
	int sum = 0;
	num = gotnum;

	for (char n : num) {
		if (n == '-') {
			minus = true;
		}
		if (n == '.' or n == ',' and d == false) {
			d = true;
		}
		for (char check : a) {
			if (a.find(n) >= sys1 and n != '.' and n != ',' and n != '-') {
				return "error. try again";
			}
			if (n == check and d == false and n != '-') {
				new_num += a.find(check);
			}
			if (n == check and d == true) {
				fraction += a.find(check);
			}
		}
	}

	int k = 1;
	for (char n : new_num) {
		sum += int(n) * pow(sys1, new_num.length() - k);
		k++;
	}
	while (sum > 0) {
		res += a[(sum % sys2)];
		sum /= sys2;
	}

	reverse(res.begin(), res.end());

	if (d == true) {
		res += ',';
		float sum = 0;
		k = -1;
		for (char n : fraction) {
			sum += int(n) * pow(sys1, k);
			k--;
		}
		k = 0;
		while (k < 10 and sum > 0) {
			res += a[int((sum * sys2) / 1)];
			sum = fmod(sum * sys2, 1);
			k++;
		}
	}

	return minus ? ("new num: -" + res) : ("new num: " + res);
}

int hw4() {
	cout << "hw4" << endl << "1) write 10 numbers " << endl;
	//1
	double x, x2, s1 = 0;
	ofstream f11("h4_1.txt");
	for (int i = 0; i < 10; i++) {
		cout << "write num " << i+1 << ": ";
		x = getDouble();
		f11 << x << endl;
	}
	f11.close();
	ifstream f12("h4_1.txt");
	x = 0;
	while (f12 >> x) {	//(!f2.eof()) {
		s1 += x;
	}
	cout << "sum: " << s1 << endl;
	f12.close();
	remove("h4_1.txt");

	//2
	cout << "2) write number" << endl;
	x2 = getDouble();
	cout << checkT(x2) << endl;

	//3
	cout << "3) for rectangle print 1, for triangle print 2, for round print 3" << endl;
	int choose = getInt();
	switch (choose) {
		case 1:
			rect();
			break;
		case 2:
			triangle();
			break;
		case 3:
			round();
			break;
		default:
			cout << "error. try again" << endl;
			hw4();
	}

	//4
	cout << "4)" << endl;
	string str="";
	bool fl = true;
	for (int i = 0; i < 14; i++) {
		if (i < 8) {
			for (int j = 0; j < 6; j++) {
				str += " * ";
			}
			if (fl) {
				for (int j = 0; j < 24; j++) {
					str += "=";
				}
			}
		}
		else {
			if (fl) {
			for (int j = 0; j < 42; j++) {
				str += "=";
			}
			}
		}
		fl = fl ? false : true;
		cout << str << endl;
		str = "";
	}
	//5
	cout << "5) y = sin(x)" << endl;
	system("pause");
	system("cls");system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	int sinm = 70;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen); //OX
	MoveToEx(hDC, 0, 100, NULL);
	LineTo(hDC, 800, 100);  //OY
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 200);
	Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	for (float x = -10.0; x <= 10.0; x += 0.01)
	{
		MoveToEx(hDC, sinm * x + 100, -sinm * sin(x) + 100, NULL);
		LineTo(hDC, sinm * x + 100, -sinm * sin(x) + 100);
	}
	
	//6
	cout << "6) write roman number" << endl;
	char lat[100];
	int count = 0;

	cin.getline(lat, 100);
	cin.getline(lat, 100);
	for (int i = 0; i < strlen(lat); i++) lat[i] = toupper(lat[i]);
	int chk = 0;
	for (int i = 0; i < strlen(lat); i++) {
		//?
	}
	for (int i = 0; i < strlen(lat); i++) {
		chk = 0;
		if (lat[i] != 'I') {
			if ((lat[i - 1] == 'I' && i==(strlen(lat)-1)) || (lat[i-1]=='I'&&lat[i+1]=='I')) { //&& (lat[i + 1] == 'I')
				count += 1;
				break;
			}
		}
		if (lat[i] == 'I') {
			int x = i;
			while (lat[x] == 'I') {
				x += 1;
				chk += 1;
			}
			if (chk >= 4 || (lat[i+1]=='L'|| lat[i + 1] == 'C' || lat[i + 1] == 'D' || lat[i + 1] == 'M')) {
				count += 1;
				break;
			}
		}
		else if (lat[i] == 'V') {
			for (int z = 0; z < strlen(lat); z++) {
				if (lat[z] == 'V')
					chk+=1;
			}
			if (chk >= 2) {
				count += 1;
				break;
			}
		}
		else if (lat[i] == 'X') {
			int x = i;
			while (lat[x] == 'X') {
				chk++;
				x++;
			}
			if (chk >= 4) {
				count += 1;
				break;
			}
			for (int z = i - 1; z >= 0; z--) {
				if (lat[z] == 'V') {
					count += 1;
					break;
				}
			}
			for (int z = i + 1; z < strlen(lat); z++) {
				if (lat[z] == 'D' || lat[z]=='M') {
					count += 1;
					break;
				}
			}
		}
		else if (lat[i] == 'L') {
			for (int z = 0; z < strlen(lat); z++) {
				if (lat[z] == 'L' || lat[z] == 'V')
					chk += 1;
			}
			if (chk >= 2) {
				count += 1;
				break;
			}
		}
		else if (lat[i] == 'C') {
			int x = i;
			while (lat[x] == 'C') {
				x += 1;
				chk += 1;
			}
			if (chk >= 4) {
				count += 1;
				break;
			}
			for (int z = i - 1; z >= 0; z--) {
				if (lat[z] == 'I' || lat[z] == 'V' || lat[z] == 'L') {
					count += 1;
					break;
				}
			}
		}
		else if (lat[i] == 'D') {
			for (int z = 0; z < strlen(lat); z++) {
				if (lat[z] == 'D')
					chk += 1;
			}
			if (chk >= 2) {
				count += 1;
				break;
			}
		}
		else if (lat[i] =='M') {
			for (int z = i - 1; z >= 0; z--) {
				if (lat[z] != 'C' && lat[z] != 'M') { //before M only C,M
					count += 1;
					break;
				}
			}
		}
	}

	if (count == 0) {
		for (int i = 0; i < strlen(lat); i++) {
			switch (lat[i]) {
			case 'M':
				count += 1000;
				break;
			case 'D':
				count += 500;
				break;
			case 'C':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'D' || lat[i + 1] == 'M'))
					count -= 100;
				else
					count += 100;
				break;
			case 'L':
				count += 50;
				break;
			case 'X':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'L' || lat[i + 1] == 'C' || lat[i + 1] == 'M'))
					count -= 10;
				else
					count += 10;
				break;
			case 'V':
				count += 5;
				break;
			case 'I':
				if (i + 1 < strlen(lat) && (lat[i + 1] == 'V' || lat[i + 1] == 'X'))
					count -= 1;
				else count += 1;
				break;
			}
		}
		cout << "decoded: " << count << endl;
	}
	else {
		cout << "error. invalid number" << endl;
	}
	
	
	//7
	cout << "7) write m,i,c" << endl;
	int m, i, c,slast,s;
	m = getInt();
	i = getInt();
	c = getInt();
	slast = 0;
	s = 0;
	cout << "s(0) = 0" <<endl;
	for (int f = 0; f <= i; f++) {
		s = (m * slast + f) % c;
		cout << "s(" << f+1 << ") = (" << m << "*" << slast << " + " << f << ") % " << c << " = " << s << endl;
		slast = s;
	}
	
	//8
	cout << "8) " << endl;
	int ma[3][4] = { {5,2,0,10}, {3,5,2,5}, {20,0,0,0} };
	double mb[4][2] = { {1.20, 0.50}, {2.80,0.40}, {5.00,1.00}, {2.00,1.50} };
	double mc[3][2];
	
	
	//cin maxtrix
	cout << "write ma:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "write " << i+1 << ' ' << j+1 << " element: ";
			int a = getInt();
			ma[i][j] = a;
		}
	}
	cout << "write mb:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "write " << i+1 << ' ' << j+1 << " element: ";
			double a = getDouble();
			mb[i][j] = a;
		}
	}
	//cout matrix
	cout << "ma:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ma[i][j] << " ";
		}
		cout << endl;
	}
	cout << "mb:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			cout << mb[i][j] << " ";
		}
		cout << endl;
	}
	

	//calc mc
	double res = 0;
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < 3; i++) {
		for (int iB = 0; iB < 2; iB++) {
			res = 0;
			for (int j = 0; j < 4; j++) { //stolb a = stroke b
				//cout << ma[i][j] << " " << mb[j][iB] << endl;
				res += ma[i][j] * mb[j][iB];
			}
			mc[c1][c2] = res;
			c2 += 1;
		}
		c1 += 1;
		c2 = 0;
	}

	//cout mc
	cout << "mc:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << mc[i][j] << "    ";
		}
		cout << endl;
	}

	//8.1
	int prodMax = 0;
	int prodMin = 0;
	double maxcom = 0;
	double mincom = 10000;
	for (int i = 0; i < 3; i++) {
		//cout << mc[i][1] << endl;
		if ((mc[i][1]+mc[i][0]) > maxcom) {
			maxcom = (mc[i][1] + mc[i][0]);
			prodMax = i + 1;
		}
		if ((mc[i][1] + mc[i][0]) < mincom) {
			mincom = (mc[i][1] + mc[i][0]);
			prodMin = i + 1;
		}
	}
	cout << "max sum: " << prodMax << endl;
	cout << "min sum: " << prodMin << endl;

	//8.2
	prodMax = 0; prodMin = 0; maxcom = 0; mincom = 100000;
	for (int i = 0; i < 3; i++) {
		//cout << mc[i][1] << endl;
		if (mc[i][1] > maxcom) {
			maxcom = mc[i][1];
			prodMax = i+1;
		}
		if (mc[i][1] < mincom) {
			mincom = mc[i][1];
			prodMin = i + 1;
		}
	}
	cout << "max commission: " << prodMax << endl;
	cout << "min commission: " << prodMin << endl;

	//8.3
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][0];
	}
	cout << "all products sum: " << res << endl;

	//8.4
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][1];
	}
	cout << "all commission sum: " << res << endl;

	//8.5
	res = 0;
	for (int i = 0; i < 3; i++) {
		res += mc[i][1] + mc[i][0];
	}
	cout << "all money: " << res << endl;

	//9
	cout << "9) " << endl;
	string num;
	int oldBase, newBase = 0;
	bool hasMinus = false;
	cout << "write num" << endl;
	//cin >> num;
	cin >> num;
	cout << "write old base" << endl;
	oldBase = getInt();
	cout << "write new base" << endl;
	newBase = getInt();

	cout << ConvertCC2(num, oldBase, newBase) << endl;
	
	return 0;
}