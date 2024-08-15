#include <iostream>
#include <queue>
#include <cstring>

#define int long long
#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 2e3 + 10;
const int M = 2e3 + 10;
const int inf = 0x3ffffffffffffff;
const int mod = 1e9 + 7;

struct Arc {
    int u, v; i64 f; int nxt; Arc() { }
    Arc(int u, int v, i64 f, int nxt) : u(u), v(v), f(f), nxt(nxt) { }
} e[M << 1];
int h[N], tot = 1;
inline void addarc(int u, int v, i64 f) {
    e[++tot] = Arc(u, v, f, h[u]), h[u] = tot;
    e[++tot] = Arc(v, u, 0, h[v]), h[v] = tot;
}

int n, m, s, t;
int u[M], v[M], c[M];
i64 d[M]; int cur[M];

inline bool bfs(int S, int T) {
    std::queue<int> q; q.push(S);
    memset(d, -1, sizeof d); d[S] = 0, cur[S] = h[S];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = h[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (!~d[v] && e[i].f) {
                d[v] = d[u] + 1; cur[v] = h[v];
                if (v == T) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}
inline i64 find(int u, int lmt, int T) {
    if (u == T) return lmt;
    i64 flow = 0;
    for (int i = cur[u]; i && flow < lmt; i = e[i].nxt) {
        cur[u] = i; int v = e[i].v;
        if (d[v] == d[u] + 1 && e[i].f) {
            int t = find(v, std::min(e[i].f, lmt - flow), T);
            if (!t) d[v] = -1;
            e[i].f -= t, e[i ^ 1].f += t; flow += t;
        }
    }
    return flow;
}
inline i64 dinic(int S, int T) {
    i64 res = 0, flow;
    while (bfs(S, T))
        while (flow = find(S, inf, T))
            res += flow;
    return res;
}

signed main() {
    file("flow");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> u[i] >> v[i] >> c[i];
    }

    i64 res = 0;

    rep (s, 1, n) rep (t, s + 1, n) {
        memset(h, 0, sizeof h); tot = 1;
        rep (i, 1, m) {
            addarc(u[i], v[i], c[i]);
            addarc(v[i], u[i], c[i]);
        }
        res = (res + dinic(s, t) % mod) % mod;
    }

    std::cout << res << '\n';

    return 0;
}