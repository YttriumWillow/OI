#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

typedef std::array<i64, 2> pll;
constexpr int N = 1e6 + 5;
int n, q, f, res, c[N]; i64 l[N];
int tim, dep[N], dfn[N];
int fa[N][20];
std::vector<pll> T[N];

void dfs(int u, int ff) {
    for (int k = 1; (1 << k) <= dep[u]; ++k)
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    for (auto P : T[u]) {
        int v = P[0]; i64 w = P[1];
        if (v == ff) continue;
        dep[v] = dep[u] + 1; l[v] = w;
        dfs(v, fa[v][0] = u);
    }
}

i64 find(int u) {
    res = std::max(res, c[u]);
    if (u == f) return 0;
    return l[u] + find(fa[u][0]);
}

int lca(int u, int v) {
    if (u == v) return u;
    if (dep[u] > dep[v]) std::swap(u, v);
    for (int k = 19; ~k; --k) {
        if (dep[v] - dep[u] >= 1 << k)
            v = fa[v][k];
    }
    if (u == v) return u;
    for (int k = 19; ~k; --k) {
        if (fa[u][k] == fa[v][k]) continue;
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k]; v = fa[v][k];
        }
    }
    return fa[u][0];
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> c[i];
    rep (i, 2, n) {
        int u, v, w;
        std::cin >> u >> v >> w;
        T[u].push_back({ v, w });
        T[v].push_back({ u, w });
    }
    dfs(1, 0);
    while (q--) {
        int x, y; std::cin >> x >> y;
        f = lca(x, y); res = 0;
        i64 d1 = find(x), d2 = find(y);
        std::cout << c[x] + c[y] + c[res] - d1 - d2 << '\n';
    }
}