#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
using namespace std;
longint fa[30010];  // 并查集
longint siz[30010]; // 集合大小
longint dis[30010]; // 到队头距离
longint T, x, y; char opr;
void Init()
{
    for (int i = 1; i <= 30000; i++)
        fa[i] = i, siz[i] = 1;
}
longint find(longint x)
{
    if (fa[x] == x)
        return x;
    longint tmp = find(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = tmp;
}
void Union(longint x, longint y)
{
    longint u = find(x), v = find(y);
    if (u == v) return;
    fa[u] = v;
    dis[u] += siz[v];
    siz[v] += siz[u];
}
int main()
{
    Init();
    scanf("%lld", &T);
    while (T--)
    {
        char ch; cin >> ch;
        scanf("%c%lld%lld", &opr, &x, &y);
        if (opr == 'M')
            Union(x, y);
        else
        {
            if (find(x) != find(y))
                printf("%d\n", -1);
            else
                printf("%lld\n", abs(dis[x] - dis[y]) - 1);
        }
    }
    return 0;
}