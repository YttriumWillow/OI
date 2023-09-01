#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define _read =read()
using namespace std;
longint n, m, x, ans;
longint fa[210];
longint ufs[210];
bool rel[210][210];
longint find(longint x)
{
    if (x != fa[x])
        x = fa[x];
    return x;
}
void unionTo(longint x, longint y)
{
    while (x != fa[x])
        x = fa[x];
    fa[y] = x;
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int main()
{
    scanf("%lld", &n);
    init();
    for (int i = 1; i <= n; i++)
        while (true)
        {
            scanf("%lld", &x);
            if (x == 0)
                break;
            rel[i][x] = true;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                rel[i][j] |= (rel[i][k] && rel[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (rel[i][j]) unionTo(i, j);
    for (int i = 1; i <= n; i++)
        ufs[find(i)] = 1;
    for (int i = 1; i <= n; i++)
        if (ufs[i])
            ans++;
    cout << ans << endl;
    return 0;
}