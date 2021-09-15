
#include <iostream>
#include "Header.h"
using namespace std;

bool isZero(int x) {
    return x == 0;
}

int getInt() {
    int a;
    while (true) {
        cin >> a;
        if (cin.fail() || cin.peek() != '\n') { //peek = �������� ���� ������ 
            cin.clear(); // �� ���������� cin � '�������' ����� ������
            cin.ignore(32777, '\n'); //32767 � ������� �������� ����������� ����� �� �������� ������
            cout << "Input error! Repeat please..." << endl;
        }
        else
            break;
    }
    return a;
}

double getDouble() {
    double a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input error! Repeat please..." << endl;
    }
    return a;
}

int main() {
	hw3();
    return 0;
}