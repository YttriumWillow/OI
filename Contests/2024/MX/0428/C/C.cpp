#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 2e5 + 10;

i64 n, a[N], b[N], d[N];

void solve() {
    i64 res = 0, l = 0x7fffffff, r = 0;

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }
    rep (i, 1, n) { std::cin >> b[i]; }

    rep (i, 1, n) res += std::abs(a[i] - b[i]);
    rep (i, 1, n) {
        l = std::min(l, std::max(a[i], b[i]));
        r = std::max(r, std::min(a[i], b[i]));
    }
    
    if (r - l > 0) res += (r - l) << 1;
    std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) { solve(); }
}