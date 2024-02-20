#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, ans, la, lb, ansa, ansb;
longint a[201], b[201];
longint rps[5][5] = {
    0, 0, 1, 1, 0,
    1, 0, 0, 1, 0,
    0, 1, 0, 0, 1,
    0, 0, 1, 0, 1,
    1, 1, 0, 0, 0
};
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read; la _read; lb _read;
    for (int i = 0; i < la; i++)
        a[i] _read;
    for (int i = 0; i < lb; i++)
        b[i] _read;
    for (int i = 0; i < n; i++)
    {
        if (rps[ a[i % la] ][ b[i % lb] ])
            ansa++;
        if (rps[ b[i % lb] ][ a[i % la] ])
            ansb++;
    }
    printf("%d %d\n", ansa, ansb);
    return 0;
}