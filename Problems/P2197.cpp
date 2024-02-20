#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, ans, T, tmp, stone;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    T _read;
    while (T--)
    {
        n _read;
        ans = 0;
        while (n--)
        {
            stone _read;
            ans ^= stone;
        }
        if (!ans)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}