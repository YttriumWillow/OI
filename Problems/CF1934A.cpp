#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int n, a[114514];

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    int res = a[n] - a[1] + a[n] - a[2] + a[n - 1] - a[1] + a[n - 1] - a[2];
    std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    offsync(); int T; std::cin >> T;
    while (T--) solve();
}