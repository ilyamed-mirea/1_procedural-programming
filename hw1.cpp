#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

int hw1()
{
    cout << "hw1" << endl;
    //1
    setlocale(LC_ALL, "Russian");
    cout << "1) Илья" << endl;

    //2
    double x, y;
    double del;
    cout << "2) Введите x и y" << endl;
    x = getDouble();
    y = getDouble();
    if (y==0) {
        del = 0.0;
    }
    else {
        del = x / y;
    }
    cout << "x+y " << (x + y) << endl
        << "x-y " << (x - y) << endl
        << "x*y " << (x * y) << endl
        << "x/y " << (del) << endl;

    //3
    double b, c;
    cout << "3) введите b и c" << endl;
    b = getDouble();
    c = getDouble();
    if (b == 0 && c == 0) {
        cout << "Бесконечное кол-во решений" << endl;
    }
    else if (b == 0 && c != 0) {
        cout << "нет решений" << endl;
    }
    else {
        int count = 0;
        for (double x = -1000; x < 1000; x+=0.1) { 
            if (((b * x) + c) == 0) {
                count++;
            }
        }
        cout << count << " решений" << endl;
    }

    //4
    double a;
    double d, x1, x2;
    a, b, c = 0;
    cout << "4) Введите a,b,c" << endl;
    a = getDouble();
    b = getDouble();
    c = getDouble();
        d = (pow(b, 2)) - (4 * a * c);
        if (d < 0) {
            cout << "нет корней" << endl;
        }
        else if (d == 0) {
            x = -b / (2 * a);
            if (x == 0)
                x = abs(x);
            cout << "x = " << x;
        }
        else if (d > 0)
        {
            x1 = (-b - sqrt(d)) / (2 * a);
            x2 = (-b + sqrt(d)) / (2 * a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }

    //5
    a, b = 0;
    cout << "ввведите состояние ламп(1/0), занавесок(1/0) и время дня - день или ночь (1/0)" << endl;
    a = getInt();
    b = getInt();
    c = getInt();
    if ((a != 0 && a != 1) || (b != 0 && b != 1) || (c != 0 && c != 1)) {
        cout << "ошибка. введите еще раз" << endl;
        a = getInt();
        b = getInt();
        c = getInt();
    }
    if (a == 1 || (b == 1 && c == 1)) {
        cout << "светло" << endl;
    }
    else {
        cout << "темно" << endl;
    }
    return 0;
}