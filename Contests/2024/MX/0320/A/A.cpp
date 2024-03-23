#include <iostream>
#include <vector>
#include <tuple>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 2e5 + 10;

int n, m, a[N], res;
bool vis[N];
std::vector<int> G[N];

#define Min first
#define Max second

void dfs(int u, int prv) {
    vis[u] = 1; res = std::max(res, a[u] - prv);
    for (auto v : G[u]) {
        if (!vis[v]) {
            dfs(v, std::min(prv, a[u]));
        }
    }
}

int main(/*int argc, char const* argv[]*/) {
    file("trade");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];

    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        G[u].push_back(v);
    }

    rep (i, 1, n) if (!vis[i]) dfs(i, a[i]);

    std::cout << res << '\n';

    return 0;
}
