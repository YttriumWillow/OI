#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 5005;
constexpr i64 mod = 0x3b800001

int n, m; i64 cnt, res;
int l[N], r[N];
int u[N], v[N], w[N];

std::set<int, i64> G[N];

void start(int u) {
    if (u == n) {
        rep (i, 1, m) fuck(u[i], v[i], w[i]); 
        rep (i, 1, n) {
            for (auto v : )
                res = (res + G[i]) % mod;
        }
        ++cnt;
    }
    rep (f, l[u], r[u]) {
        G[f].insert(u);
        G[u].insert(f);
        start(u + 1);
        G[f].erase(u);
        G[u].erase(f);
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> l[i] >> r[i];
    }
    std::cin >> m;
    rep (i, 1, m) {
        std::cin >> u[i] >> v[i] >> w[i];
    }

    start(2);
}