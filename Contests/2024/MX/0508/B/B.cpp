#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 7;

int n, a[N];
int fac[N << 2], _2[N << 2];

void init(int n) {
    fac[0] = 1; _2[0] = 1;
    rep (i, 1, 2 * n) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        _2[i] = (_2[i - 1] << 1) % mod; 
    }
}
int fpow(int a, int k) {
    int res = 1;
    for (; k; k >>= 1) {
        if (k & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}
int inv(int a) { return fpow(a, mod - 2); }

// n is down
int C(int n, int m) {
    if (n < m) { std::cerr << "C(" << n << ", " << m << ") is invalid\n"; abort(); }
    return 1ll * fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

int main(/*int argc, char const* argv[]*/) {
    file("seq");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n; init(n);
    rep (i, 1, n) { std::cin >> a[i]; }

    std::sort(a + 1, a + n + 1);

    int res = 0;

    rep (i, 1, n) {
        if (a[i] <= i) {
            res = ( res + 1ll * C(i - 1, a[i] - 1) * _2[n - i] % mod ) % mod;
        }
    }

    std::cout << res << '\n';
}