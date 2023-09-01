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
    longint u, v, w, next;
    Edge() {}
    Edge(longint _u, longint _v, longint _w, longint _n) : u(_u), v(_v), w(_w), next(_n) {}
} edge[200014];
struct Node
{
    longint w, now;
    Node() {}
    Node(longint _w, longint _n): w(_w), now(_n) {}
    inline friend bool operator < (const Node &_x, const Node &_y) { return _x.w > _y.w; }
};
longint n, m, s, tot;
longint dis[100010], head[100010];
bool vis[100010];
inline void addEdge(longint u, longint v, longint w)
{
    edge[++tot] = Edge(u, v, w, head[u]);
    head[u] = tot;
}
void dijkstra()
{
    priority_queue<Node> q;
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    q.push(Node{0, s});
    while (!q.empty())
    {
        Node x = q.top(); q.pop();
        int u = x.now;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                q.push(Node{dis[v], v});
            }
        }
    }
}
int main()
{
    n _read; m _read; s _read;
    for (longint i = 1, u, v, w; i <= m; i++)
    {
        u _read; v _read; w _read;
        addEdge(u, v, w);
    }
    dijkstra();
    for (longint i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}