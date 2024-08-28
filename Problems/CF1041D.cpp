#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;
int n, h;
int l[N], r[N]; i64 res, d[N];

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n >> h;
    rep (i, 1, n) std::cin >> l[i] >> r[i];

    rep (i, 1, n) d[i] = d[i - 1] + l[i] - r[i - 1];

    rep (i, 1, n) {
        int p = std::lower_bound(d + 1, d + n + 1, h + d[i]) - d - 1;
        res = std::max(res, r[p] - l[i] + h - d[p] + d[i]);
    }

    std::cout << res << '\n';
}