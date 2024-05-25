#include <iostream>

#define i64 long long
#define ull unsigned long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int T; ull l, r, k;

void solve() {
    std::cin >> l >> r >> k;
    bool o = 0;

    if (k == 0) {
        if (l <= 0 and 0 <= r) std::cout << 0 << ' ', o = 1;
        if (l <= 1 and 1 <= r) std::cout << 1 << ' ', o = 1;
        std::cout << (o ? "" : "None.") << '\n'; return;
    }
    else if (k == 1) {
        if (l <= 1 and 1 <= r) std::cout << 1 << ' ', o = 1;
        std::cout << (o ? "" : "None.") << '\n'; return;
    }

    __int128 v = 1;
    rep (i, 1, 63) {
        if (v > r) break;
        if (v >= l) std::cout << (i64)v << ' ', o = 1;
        v *= k;
    }
    std::cout << (o ? "" : "None.") << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    file("output");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> T; while (T--) solve();
}