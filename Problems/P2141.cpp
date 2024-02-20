#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, s[110], ans;
bool vis[110];
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
    for (int i = 1; i <= n; i++)
        s[i] _read;
    for (int p1 = 1; p1 < n; p1++)
        for (int p2 = p1 + 1; p2 <= n; p2++)
            for (int k = 1; k <= n; k++)
                if (k != p1 && k != p2 && s[p1] + s[p2] == s[k] && vis[k] == 0)   //没有数过并且不是边界
                {
                    ans++;
                    vis[k] = 1;
                }
    cout << ans << endl;
    return 0;
}