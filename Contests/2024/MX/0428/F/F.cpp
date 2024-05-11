#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define per(i, r, l) for (int i = (r); i >= l; --i)
#define fuck(V) ((V) > 0)

i64 n, b, T;
i64 f[51][65536];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> b;

    rep (i, 0, (1 << n) - 1) rep (j, 0, n - 1)
        f[0][i] += (1 << j) * (((i & 1 << (j + 1) % n) > 0) ^ ((i & 1 << j) > 0));
    rep (i, 1, 50) rep (j, 0, (1 << n) - 1)
        f[i][j] = f[i - 1][f[i - 1][j]];

    rep (i, 1, n) {
        i64 v; std::cin >> v;
        T = T << 1 | v;
    }
    per (i, 50, 0) if (1LL << i <= b) {
        b -= 1ll << i;
        T = f[i][T];
    }
    per (i, n - 1, 0)
        std::cout << ((T & 1 << i) > 0) << '\n';
}