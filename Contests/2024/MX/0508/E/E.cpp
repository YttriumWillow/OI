#include <iostream>
#include <algorithm>
#include <cstring>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define per(i, r, l) for (int i = (r); i >= l; --i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e5 + 10;
constexpr int V = 1e7 + 10;

int n, a[N], v[V], f[V], g[V], res;

int main(/*int argc, char const* argv[]*/) {
    file("pile");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }


    int prv = 0;
    rep (i, 1, n) {
        int t = std::lower_bound(v, v + prv + 1, a[i]) - v;
        v[t] = a[i];
        if (prv < t) prv = t;
        f[i] = prv;
    }

    memset(v, 0, sizeof v);

    prv = 0;
    per (i, n, 1) {
        int t = std::lower_bound(v, v + prv + 1, a[i]) - v;
        v[t] = a[i];
        if (prv < t) prv = t;
        g[i] = prv;
    }

    rep (i, 1, n) res = std::max(res, f[i] + g[i] - 2);

    std::cout << res << '\n';

}