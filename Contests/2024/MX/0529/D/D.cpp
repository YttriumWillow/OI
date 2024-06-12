#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 5e4 + 10;
constexpr int M = 5e4 + 10;
constexpr int inf = 0x7fffffff;

int tot = 1, h[N];
struct E { int v, w, nxt; } e[M << 1];
inline void add(int u, int v, int w) {
    e[++tot] = { v, w, h[u] }; h[u] = tot;
}

int n, m, k;

int d[N]; bool vis[N];

bool check(int mid) {
    std::fill(d + 2, d + n + 1, inf);
    std::fill(vis, vis + n + 1, 0);
    std::priority_queue<std::pair<int, int>> Q;
    Q.push({ 0, 1 });
    while (not Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (int i = h[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            int p = w < mid ? 0 : (w - mid);
            if (d[v] > d[u] + p) {
                d[v] = d[u] + p;
                Q.push({ -d[v], v });
            }
        }
    }
    return d[n] <= k ? 1 : 0;
}


int main(/*int argc, char const* argv[]*/) {
    file("ride");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m >> k;

    rep (i, 1, m) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(u, v, w); add(v, u, w);
    }

    int l = 0, r = 5e4;
    while (l < r) {
        int mid = (l + r) >> 1;
        check(mid) ? r = mid : l = mid + 1;
    }

    std::cout << l << '\n';
}