#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 4e6 + 10;

i64 n, d, q, a[N], p[N];

signed main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> d >> q;
    rep (i, 1, n) { std::cin >> a[i]; }

    while (q--) {
        i64 l, x; std::cin >> l >> x;
        p[l] = std::max(p[l], x);
    }

    i64 now = 0;
    rep (i, 1, n) {
        if (p[i] > now) { now = p[i]; }
        a[i] = std::max(a[i], now);
        now += d;
    }

    rep (i, 1, n) {
        std::cout << a[i] << ' ';
    }

}