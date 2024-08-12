#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 5e5 + 5;

int n, a[N];
int cnt[32], c0; i64 res;

void clear() {
    rep (i, 0, 31) { cnt[i] = 0; }
    res = 0; c0 = 0;
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }
    std::sort(a + 1, a + n + 1);
    rep (i, 1, n) if (!a[i]) {
        ++c0;
    } else {
        for (int j = 31, f = 0; ~j; --j) {
            if ((a[i] >> j) & 1) {
                f ? (res += cnt[j]) : (++cnt[j], f = 1);
            }
        }
    }
    res += 1ll * c0 * n;
    std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) { solve(); clear(); }
}