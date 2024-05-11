#include <iostream>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 4e6 + 10;
const i64 mod = 147744151;

int P, Q, R1, R2;
i64 fac[N];

i64 fpow(i64 a, i64 k) {
    i64 res = 1;
    for (; k; k >>= 1) {
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
i64 inv(i64 v) { return fpow(v, mod - 2); }

void init() {
    fac[0] = 1;
    rep (i, 1, 400000) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

void solve() {
    std::cin >> P >> Q >> R1 >> R2;

    i64 res = 1;
    // rep (i, 1, P + Q)
    //     res = res * inv(R1 + R2 + i - 1) % mod;

    res = res * fac[R1 + R2 - 1] % mod;
    res = res * inv(fac[R1 + R2 + P + Q - 1]) % mod;

    // rep (i, 1, P)
    //     res = res * (R1 + i - 1) % mod;

    res = res * fac[R1 + P - 1] % mod;
    res = res * inv(fac[R1 - 1]) % mod;

    // rep (i, 1, Q)
    //     res = res * (R2 + i - 1) % mod;

    res = res * fac[R2 + Q - 1] % mod;
    res = res * inv(fac[R2 - 1]) % mod;

    res = res * fac[P + Q] % mod;
    res = res * inv(fac[P]) % mod * inv(fac[Q]) % mod;

    std::cout << res << '\n';

}


int main(/*int argc, char const* argv[]*/) {
    file("chess");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T; init();
    while (T--) { solve(); }
}