#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 5e5 + 10;

int n, Q, a[N]; i64 sum[N];
int l, r, p; int v[510];

int solve() {
    std::cin >> l >> r >> p;
    if (r - l + 1 >= p) { return 0; }
    std::fill(v, v + p, -1);

    rep (i, l - 1, r) {
        if (~v[sum[i] % p]) { return 0; }
        v[sum[i] % p] = i;
    }

    int res = p;
    rep (x, 0, p - 1) rep (y, x + 1, p - 1) {
        if (~v[x] and ~v[y]) {
            res = std::min(res,
                (v[x] < v[y] ?
                    ((y - x + p) % p) : ((x - y + p) % p))
            );
        }
    }
    return res;
}

int main(/*int argc, char const* argv[]*/) {
    file("sum");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> Q;
    rep (i, 1, n) { std::cin >> a[i]; }
    rep (i, 1, n) { sum[i] = sum[i - 1] + a[i]; }

    while (Q--) { std::cout << solve() << '\n'; }
}