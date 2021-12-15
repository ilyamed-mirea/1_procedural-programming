#include <iostream>
#include "Header.h"

using namespace std;

int getInt() {
    int a;
    while (true) {
        cin >> a;
        if (cin.fail() || cin.peek() != '\n') { //peek = проверка след символ 
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32777, '\n'); //32767 и удаляем значения предыдущего ввода из входного буфера
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
    //hw1();
    //hw2();
	//hw3();
    //hw4();
    //hw5();
    //hw6();
    //spin();
    //d98();
    //d99();
    return 0;
}