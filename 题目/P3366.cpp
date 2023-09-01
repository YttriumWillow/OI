/*
    FileName: P_3366_模板_最小生成树.cpp
        + randomhash: 0f6571606655efe23a3bca46
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/25 星期二
    Time: 19:31:37
        + Unix Timestamp(second): 1666697497
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

const int inf = 1145141919;

struct Edge
{
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    friend bool operator < (Edge _x, Edge _y) { return _x.w < _y.w; }
} edge[400010];

int n, m; bool flag;
int fa[10010], cnt, ans;

inline int find(int x)
{
    if (fa[x] == x) return fa[x];
    return fa[x] = find(fa[x]);
}

inline int kruskal()
{
    reg int ans = 0;
    sort(edge + 1, edge + m + 1);
    for (reg int i = 1; i <= m; i++)
    {
        reg int x = find(edge[i].u);
        reg int y = find(edge[i].v);
        if (x == y) continue;
        ans += edge[i].w; fa[x] = y;
        if (++cnt == n - 1)
        {
            flag = true;
            break;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        fa[i] = i;
    for (reg int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = Edge(u, v, w);
    }
    ans = kruskal();
    if (!flag)
    {
        printf("orz\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}