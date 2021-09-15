#include <iostream>
#include <cstdlib> // для system
#include <cmath>
#include "Header.h"
using namespace std;

int hw2()
{
    cout << "hw2" << endl;
    //1
    int h,R,r,l = 0;
    double V, S;
    cout << "1) write h,R,r" << endl;
    //cin >> h >> R >> r >> l;
    h = getInt();
    R = getInt();
    r = getInt();
    l = sqrt(pow(h, 2) + pow((R - r), 2));
    V=((float)1/3)*M_PI*h*(pow(R,2)+(R*r)+pow(r,2));
    S=M_PI*(pow(R,2)+((R+r)*l)+pow(r,2));
    cout << "V: " << V << " S: " << S << endl;

    //2
    int x,a = 0;
    double w = 0;
    cout << "2) write x,a" << endl;
    x = getInt();
    a = getInt();
    x = abs(x);
    if (x<1 && x!=0) {
        w = a * log(x);
    }
    else if (pow(x, 2) < a) {
        w = sqrt(a-pow(x,2));
    }
    else {
        cout << "error" << endl;
    }
    cout << "w: " << w << endl;

    //3
    int y,b=0;x=0;
    double z;
    cout << "3) write x,y,b" << endl;
    ///cin >> x >> y >> b;
    x = getInt();
    y = getInt();
    b = getInt();
    if (y > b && x > b) {
        z = log(b - y) * sqrt(b - x);
        cout << "z: " << z << endl;
    }
    else {

        cout << "error." << endl;
    }

    //4
    cout << "4) write N" << endl;
    x = getInt();
    if (x < 0) x = 0;
    for (int i = x; i < x + 10; i++) {
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
