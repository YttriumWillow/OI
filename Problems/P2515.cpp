#include <iostream>
#include <vector>

#define i64 long long
#define rep(i, l, r) for(int i = l; i <= (r); ++i)
#define per(i, r, l) for(int i = r; i >= (l); --i)

constexpr int N = 510;

int n, m;
int w[N], a[N], d[N];
int dfn[N], low[N], blk[N], st[N], in[N];
int cnt, scc, tp; bool ins[N];
std::vector<int> G[N], NG[N];
int _w[N], _v[N], f[N][N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt; ins[u] = 1; st[++tp] = u;
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v),
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            blk[u] = scc; ins[u] = 0;
            _w[scc] += w[u];
            _v[scc] += a[u];
            u = st[tp--];
        } while (low[u] != dfn[u]);
        // while (st[tp + 1] != u) {
        //     blk[st[tp]] = scc;
        //     _w[scc] += w[st[tp]]; 
        //     _v[scc] += a[st[tp]];
        //     ins[st[tp--]] = 0;
        // }
    } 
}

void dfs(int u) {
    rep (i, _w[u], m) {
        f[u][i] = _v[u];
    }
    for (auto v : NG[u]) {
        dfs(v); int k = m - _w[u];
        per (i, k, 0) rep (j, 0, i) {
            f[u][i + _w[u]] = std::max(f[u][i + _w[u]], f[v][j] + f[u][i + _w[u] - j]);
        }
    }
}

int main(/*int argc, char const *argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> w[i];
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) {
        std::cin >> d[i];
        if (d[i]) G[d[i]].push_back(i);
    }

    rep (i, 1, n)
        if (!dfn[i]) tarjan(i);
    rep (i, 1, n) {
        if (blk[d[i]] != blk[i]) {
            NG[blk[d[i]]].push_back(blk[i]); ++in[blk[i]];
        }
    }
    rep (i, 1, scc) {
        if (!in[i]) NG[0].push_back(i);
    }

    dfs(0);
    std::cout << f[0][m] << '\n';
 
}
