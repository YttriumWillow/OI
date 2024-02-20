#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
const int inf = 0x3fffffff;
inline int read()
{
    int x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int n, m, s, u, v, w;
int edge[10010][10010];
inline void floyd()
{
    for (reg int k = 1; k <= n; k++)
        for (reg int i = 1; i <= n; i++)
        {
            if (i == k || edge[i][k] == inf)
                continue;
            for (int j = 1; j <= n; j++)
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
        }
}
int main()
{
    n _read; m _read; s _read;
    for (reg int i = 1; i <= n; i++)
        for (reg int j = 1; j <= n; j++)
            edge[i][j] = inf;
    for (reg int i = 1; i <= m; i++)
    {
        u _read; v _read; w _read;
        edge[u][v] = min(w, edge[u][v]);
    }
    floyd();
    edge[s][s] = 0;
    for (reg int i = 1; i <= n; i++)
        printf("%d ", edge[s][i]);
    return 0;
}