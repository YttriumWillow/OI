#include <iostream>
#include <algorithm>
#include <vector>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

#define x first
#define y second

constexpr int N = 1e5 + 10;

int n, prv[11];
std::pair<i64, i64> P[N];
std::vector<int> G[N];

namespace dsu {
    int fa[N];
    void init(int n) { rep (i, 1, n) fa[i] = i; }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) { fa[find(x)] = find(y); }
} // using namespace dsu;

struct Edge {
    int u, v; i64 w;
    friend bool operator < (const Edge& X, const Edge& Y) {
        return X.w < Y.w;
    }
};
Edge e[N * 22]; int tot = 0;
i64 dis(std::pair<i64, i64>& A, std::pair<i64, i64>& B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
void add(int u, int v) {
    e[++tot] = { u, v, dis(P[u], P[v]) };
}

i64 kruskal() {
    dsu::init(n);
    std::sort(e + 1, e + tot + 1);
    i64 res = 0;
    rep (i, 1, tot) {
        int u = dsu::find(e[i].u);
        int v = dsu::find(e[i].v);
        if (u == v) { continue; }
        else { dsu::merge(u, v); res += e[i].w; }
    }
    return res;
}

int main(/*int argc, char const* argv[]*/) {
    file("ant");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> P[i].x >> P[i].y; }

    std::sort(P + 1, P + n + 1);

    rep (i, 1, n) {
        rep (j, 0, 10)
            if (prv[j]) add(i, prv[j]);
        prv[P[i].y] = i;
    }

    std::cout << kruskal() << '\n';

}