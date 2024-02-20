#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, k;
longint a[1010][1010], ans[1010];
bool check[1010][1010];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read; m _read; k _read;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] _read;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!check[j][a[i][j]])
            {
                check[j][a[i][j]] = 1;
                ans[a[i][j]]++;
            }
    for (int i = 1; i <= k; i++)
        cout << ans[i] << ' ';
    return 0;
}