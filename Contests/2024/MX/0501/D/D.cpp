#include <iostream>
#include <vector>
#include <tuple>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 2e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f;

int n, D, Md; i64 cnt, res = inf;
std::vector<std::pair<int, int>> G[N];

struct E {
    int v, w, nxt;
} e[N]; int h[N], tot = 1; bool f[N];
void add(int u, int v, int w) {
    e[++tot] = { v, w, h[u] }; h[u] = tot;
}


inline void dfs(int u, int fa, int d) {
    Md = std::max(Md, d);
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].v; int w = e[i].w;
        if (v == fa) continue;
        cnt += f[i]; dfs(v, u, d + w);
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> D;
    rep (i, 2, n) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(v, u, w); add(u, v, w); f[tot] = 1;
    }

    rep (i, 1, n) {
        cnt = 0; Md = 0;
        dfs(1, 0, 0);
        if (Md <= D) res = std::min(res, (i64)Md);
    }

    std::cout << (res == inf ? -1 : res) << '\n';

}