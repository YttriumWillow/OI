#include <iostream>
#include <algorithm>
#define reg register
#define endl '\n'
struct Edge
{
    int u, v, w;
    // bool operator<(Edge _x) { return w < _x.w; }
} edge[600001];

int n, m;
int fa[100001], cnt;

// inline int find(int x)
// {
//     if (fa[x] == x)return fa[x];
//     return fa[x] = find(fa[x]);
// }

bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

inline long long kruskal()
{
    reg long long ans = 0;
    std::sort(edge + 1, edge + m + 1, cmp);
    for (reg int i = 1; i <= m; ++i)
    {
        reg int x = find(edge[i].u);
        reg int y = find(edge[i].v);
        if (x == y) continue;
        ans += edge[i].w;
        fa[x] = y;
        if (++cnt == n - 1) break;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1;i <= n;++i) fa[i] = i;
    for (reg int i = 1, u, v, w; i <= m;++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge[i].u = u; edge[i].v = v; edge[i].w = w;
    }
    printf("%lld\n", kruskal());
    return 0;
}