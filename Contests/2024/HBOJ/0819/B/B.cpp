#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 5;
constexpr int M = 2e5 + 5;
constexpr i64 inf = 1000000000000000000;

struct Graph {
    static constexpr int N = ::N * 4;
    static constexpr int M = ::M * 18;
    int h[N], tot = 1;
    struct Edge { int v; i64 w; int nxt; } e[M];
    void add(int u, int v, i64 w) {
        e[++tot] = { v, w, h[u] }; h[u] = tot;
    }
};
int n, m; Graph G;
i64 d[N * 4]; bool vis[N * 4];
typedef std::pair<i64, int> Pii;

void dijkstra(int u, i64 *d) {
    std::priority_queue<Pii, std::vector<Pii>, std::greater<Pii>> Q;
    std::fill(d, d + 4 * n + 1, inf);
    std::fill(vis, vis + 4 * n + 1, 0);
    Q.push({0, 1}); d[u] = 0;

    while (!Q.empty()) {
        auto u = Q.top().second; Q.pop();
        if (vis[u]) { continue; } vis[u] = 1;
        for (int i = G.h[u]; i; i = G.e[i].nxt) {
            int v = G.e[i].v, w = G.e[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w; Q.push({d[v], v});
            }
        }
    }
}

int main(/*int argc, char const* argv[]*/) {
    // file("flower");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    
    rep (i, 1, m) {
        int u, v, w; std::cin >> u >> v >> w;

        G.add(u + n * 0, v + n * 0, w);
        G.add(u + n * 0, v + n * 1, 0);
        G.add(u + n * 0, v + n * 2, w * 2);
        G.add(u + n * 0, v + n * 3, w);
        G.add(u + n * 1, v + n * 1, w);
        G.add(u + n * 1, v + n * 3, w * 2);
        G.add(u + n * 2, v + n * 2, w);
        G.add(u + n * 2, v + n * 3, 0);
        G.add(u + n * 3, v + n * 3, w);

        G.add(v + n * 0, u + n * 0, w);
        G.add(v + n * 0, u + n * 1, 0);
        G.add(v + n * 0, u + n * 2, w * 2);
        G.add(v + n * 0, u + n * 3, w);
        G.add(v + n * 1, u + n * 1, w);
        G.add(v + n * 1, u + n * 3, w * 2);
        G.add(v + n * 2, u + n * 2, w);
        G.add(v + n * 2, u + n * 3, 0);
        G.add(v + n * 3, u + n * 3, w);
    }

    dijkstra(1, d);

    rep (i, 2, n) std::cout << d[i + n * 3] << ' ';
}