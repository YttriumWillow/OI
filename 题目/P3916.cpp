#include <bits/stdc++.h>
#define longint long long
#define _read =read()
#define qwq printf("fzy_qwq\n");
using namespace std;
longint n, m, u, v, a[100010];
vector<longint> g[100010];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while ( ch < '0' || ch > '9' ) { if (ch == '-') sgn = -1; ch = getchar(); }
    while ( ch >= '0' && ch <= '9' ) { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
void dfs(longint now, longint d)
{
    if (a[now])
        return;
    a[now] = d;
    longint len = g[now].size();
    for (int i = 0; i < len; i++)
        dfs(g[now][i], d);
}
int main()
{
    n _read; m _read;
    for (int i = 1; i <= m; i++)
    {
        u _read; v _read;
        g[v].push_back(u);
    }
    for (int i = n; i >= 1; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    return 0;
}