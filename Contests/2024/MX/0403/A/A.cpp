#include <iostream>
#include <functional>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const i64 N = 1e6 + 10;
const i64 mod = 998244353ll;
const i64 inv2 = 499122177ll;

i64 n, m, res, sum;

i64 fpow(i64 a, i64 k) {
    i64 res = 1;
    for (; k; k >>= 1) {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res % mod;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;

    res = n * (n - 1) % mod * inv2 % mod * fpow(m, n - 2) % mod;

    rep (i, 1, m) {
        sum = (sum + i * ((i + 1) >> 1) % mod) % mod;
    }

    rep (i, 2, m) {
        sum = (sum + ((m + i) >> 1) * (m - i + 1) % mod) % mod;
    }

    std::cout << res * sum % mod << '\n';

}