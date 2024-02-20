#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint a, b, n;
double sha;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    a _read; b _read;
    if (a > b) swap(a, b);
    n = b - a;
    sha = (1.0 * n * ( (1.0 + sqrt(5.0)) / 2.0));
    // cout << sha << endl;
    if ( (longint)sha == a )
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return 0;
}