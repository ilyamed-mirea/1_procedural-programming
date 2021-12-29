#include <iostream>
#include <cstdlib> // для system
#include <cmath>
#include "Header.h"
using namespace std;

int hw2()
{
    cout << "hw2" << endl;
    //1
    double h,R,r,l = 0;
    double V, S;
    bool fl = true;
    while (fl) {
        cout << "1) write h,R,r" << endl;
        fl = false;
        //cin >> h >> R >> r >> l;
        h = getDouble();
        R = getDouble();
        r = getDouble();
        if (h < 0 || R < 0 || r < 0) {
            cout << "error. try again" << endl;
            fl = true;
        }
        else {
            l = sqrt(pow(h, 2) + pow((R - r), 2));
            V = M_PI * h * (pow(R, 2) + (R * r) + pow(r, 2)) / 3;
            S = M_PI * (pow(R, 2) + ((R + r) * l) + pow(r, 2));
            cout << "V: " << V << endl << " S: " << S << endl;
        }
    }

    //2
    double x,a = 0;
    double w = 0;
    fl = true;
    while (fl) {
        cout << "2) write x,a" << endl;
        fl = false;
        x = getDouble();
        a = getDouble();
        x = abs(x);
        if (x < 1 && x != 0) {
            w = a * log(x);
            cout << "w: " << w << endl;
        }
        else if (a > pow(x, 2)) {
            w = sqrt(a - pow(x, 2));
            cout << "w: " << w << endl;
        }
        else {
            cout << "error. try again" << endl;
            fl = true;
        }
    }
    

    //3
    double y,b=0;x=0;
    double z;
    ///cin >> x >> y >> b;
    fl = true;
    while (fl) {
        cout << "3) write x,y,b" << endl;
        fl = false;
        x = getDouble();
        y = getDouble();
        b = getDouble();
        if (b - x < 0 || b - y <= 0) {
            cout << "error.. try again" << endl;
            fl = true;
        }
        else {
            z = log(b - y) * sqrt(b - x);
            cout << "z: " << z << endl;
        }
    }

    //4
    cout << "4) write N" << endl;
    x = getDouble();
    for (double i = x; i < x + 10; i++) {
         if (i > 0)
            cout << i << " ";
    }
    cout << endl;

    //5
    cout << "5) " << endl;
    for (double x = -4; x <= 4; x += 0.5) {
        if (x != 1) {
            cout << "x: " << x << "; y: " << (((pow(x, 2) - (2 * x) + 2)) / (x - 1)) << endl;
        }
        else {
            cout << "x: " << x << ";y: error" << endl;
        }
    }

    return 0;
}
