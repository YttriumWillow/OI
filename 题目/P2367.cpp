#include <bits/stdc++.h>
#define longint long long
#define reg register int
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
longint n, p, x, y, z, ans = 1145141919810, awa;
longint a, b, diff[5000010];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read; p _read;
    for (reg i = 1; i <= n; i++)
    {
        a _read;
        diff[i] = a - b;
        b = a;
    }
    while (p--)
    {
        x _read; y _read; z _read;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    for (reg i = 1; i <= n; i++)
    {
        awa += diff[i];
        ans = min(ans, awa);
    }
    cout << ans << endl;
    return 0;
}