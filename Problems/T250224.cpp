#include <bits/stdc++.h>
#define longint long long
#define _read =read()
using namespace std;
longint n, m, T, S;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    S _read;
    T _read;
    while ( T-- )
    {
        n _read; m _read;
        printf("%lld %lf\n", n * m - ((n + 1) / 2) * ((m + 1) / 2), 0.0);
    }
    return 0;
}