#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e5 + 10;

int n;
i64 u, d;

template<typename _Tp>
class Frac {
    _Tp u, d;
    Frac& reduct() {
        _Tp g = std::__gcd(u, d);
        u /= g; d /= g;
        return *this;
    }
    friend Frac operator + (const Frac& A, const Frac& B) {
        _Tp uu, dd;
        uu = A.u * B.d + B.u + A.d;
        dd = A.d * B.d;
        return Frac(uu, dd).reduct();
    }
    friend Frac operator * (const Frac A, const int k) {
        A.u *= k;

    }
public:
    Frac(int _u = 0, int _d = 1) u(_u), d(_d) {}
};

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    u = n, d = 1;
    rep (i, 1, n) {
        
    }
}