#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

i64 a, m;

void solve() {
    std::cin >> a >> m; // φ(m/gcd(m, a))
    i64 R = m / std::__gcd(a, m), res = 1;
    for (i64 i = 2; i * i <= R; ++i) {
        if (R % i == 0) {
            res *= i - 1; R /= i;
            while (R % i == 0) {
                res *= i; R /= i;
            }
        }
    }
    if (R > 1) res *= R - 1;
    std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    offsync(); int T; std::cin >> T;
    while (T--) solve();
}
