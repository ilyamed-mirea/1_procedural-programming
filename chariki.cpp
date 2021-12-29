#include <iostream>
#include "Header.h"
using namespace std;

int res = 0;

void swapp(int a, int b, int arr[])
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}
void recursion(int k, int N, int arr[])
{
    if (k == N)
    {
        bool b = false;
        for (int i = 0; i < N; i++) {
            if (arr[i] == i + 1) {
                b = true;
            }
        }
        if (b == true) {
            res += 1;
        }
    }
    else
    {
        for (int j = k; j < N; j++)
        {
            swapp(k, j, arr);
            recursion(k + 1, N, arr);
            swapp(k, j, arr);
        }
    }
}

int chariki()
{
    int N;
    cout << "write colvo sharikov: ";
    N = getInt();
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;
    recursion(0, N, arr);
    cout << endl << "answer: " << res << endl;

    return 0;
}