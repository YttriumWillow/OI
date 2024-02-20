#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
struct Carpet
{
    longint a, b, x, y;
} carpet[10010];

longint n, ans, g, k, x, y;

inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read;
    for (int i = n; i >= 1; i--)
    {
        carpet[i].a _read;
        carpet[i].b _read;
        g _read; k _read;
        carpet[i].x = carpet[i].a + g;
        carpet[i].y = carpet[i].b + k;
    }
    x _read; y _read;
    for (int i = 1; i <= n; i++)
    {
        if (carpet[i].x >= x && carpet[i].y >= y && carpet[i].a <= x && carpet[i].b <= y)
        {
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}