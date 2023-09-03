#include <bits/stdc++.h>
#define longint long long
#define _read =read()
using namespace std;
longint n, T, S, x, y, tmp;
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
    while(T--)
    {
        n _read; x _read; y _read;
        for(int i = 1; i <= n; i++)
            tmp _read;
        cout << 0;
        for(int i = 1; i < tmp; i++)
            cout << 0;
        cout << endl;
        for(int i = 1; i <= x; i++)
            cout << '^';
        
    }
    return 0;
}