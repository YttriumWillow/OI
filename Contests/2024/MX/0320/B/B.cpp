#include <iostream>
#include <vector>
#include <tuple>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 2e5 + 1000;
const int mod = 1e9 + 7;

int n, m, siz, res;
int a[N], fac[N], inv[N];

int fpow(int a, int k) {
    int res = 1;
    for (; k; k >>= 1) {
        if (k & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}
void init(int n) {
    fac[0] = 1; inv[0] = 1;
    rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
    rep (i, 1, n) inv[i] = fpow(fac[i], mod - 2);
}

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main(/*int argc, char const* argv[]*/) {
    file("paper");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n + 1) {
        std::cin >> a[i];
        siz = std::max(siz, i + a[i] + 10);
    }

    init(siz);

    rep (i, 1, n + 1) {
        res = (res + C(i + a[i] - 1, a[i] - 1) % mod) % mod;
    }

    std::cout << res << '\n';

    return 0;
}

/*
5
8 6 6 5 3 1
*/