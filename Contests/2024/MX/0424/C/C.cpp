#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e5 + 10;
const int mod = 147744151;

int n, k, c1, c2, a[N];
int fac[N];

void solve() {
    std::cin >> n >> k; c1 = c2 = 0;
    rep (i, 1, n) {
        std::cin >> a[i];
        (a[i] & 1) ? ++c1 : ++c2;
    }

    if (k) {
        if (n & 1) {
            if (std::abs(c1 - c2) != 1) { std::cout << 0 << '\n'; return; }
            std::cout << (1ll * fac[c1] * fac[c2] % mod + 1 - k + mod) % mod << '\n';
        }
        else {
            if (c1 != c2) { std::cout << 0 << '\n'; return; }
            std::cout << (1ll * fac[c1] * fac[c2] * 2) % mod << '\n';
        }
    }
    else {
        if (c1 != 0 and c2 != 0) { std::cout << 0 << '\n'; return; }
        std::cout << fac[n] - k << '\n';
    }
}

int main(/*int argc, char const* argv[]*/) {
    // file("perm");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    fac[0] = 1;
    rep (i, 1, 100000) fac[i] = 1ll * fac[i - 1] * i % mod;

    int T; std::cin >> T;
    while (T--) { solve(); }
}