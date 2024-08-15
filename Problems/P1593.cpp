#include <iostream>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr i64 mod = 9901;

i64 A, B, res = 1, t;

template<typename _Tp> _Tp fpow(_Tp a, _Tp k) {
    _Tp res = 1;
    for (; k; k >>= 1) {
        if (k & 1) res = (i64)res * a % mod;
        a = (i64)a * a % mod;
    } return res;
}
template<typename _Tp> _Tp inv(_Tp a) { return fpow(a, (_Tp)mod - 2) % mod; }


int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> A >> B;
    if (A == 0) { std::cout << 0 << '\n'; return 0; }
    rep (i, 2, A) {
        if (!(A % i)) {
            t = 0;
            while (A % i == 0) t++, A /= i;
            if (i % mod == 1) res = res * (t + 1) % mod;
            else res = res * ((fpow((i64)i, t * B + 1) - 1) * inv(i - 1)) % mod;
        }
    }
    std::cout << (res % mod + mod) % mod << '\n';
}