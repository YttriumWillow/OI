#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
const longint inf = 0x7fffffff;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
struct Edge
{
    longint next, to, w;
    Edge() {}
    Edge(longint _n, longint _t, longint _w) : next(_n), to(_t), w(_w) {}
} edge[200014];
longint n, m, s, tot;
longint dis[100010], head[100010];
bool vis[100010];
inline void SPFA()
{
    queue<longint> q;
    for (longint i = 1; i <= n; i++)
        dis[i] = inf;
    longint u, v; q.push(s);
    dis[s] = 0; vis[s] = true;
    // 起点距离为 0, 并以访问
    while (!q.empty())
    {
        u = q.front(); q.pop(); vis[u] = false;
        // 弹出一个节点来更新
        for (longint i = head[u]; i; i = edge[i].next)
        {
            v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
inline void addEdge(longint u, longint v, longint w)
{
    edge[++tot] = Edge(head[u], v, w);
    head[u] = tot;
}
int main()
{
    n _read; m _read; s _read;
    for (longint i = 1, u, v, w; i <= m; i++)
    {
        u _read; v _read; w _read;
        addEdge(u, v, w);
    }
    SPFA();
    for (longint i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}