#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e6 + 10;
int n, v;

void solve() {
    std::cin >> n;
    int pos1, pos2, npos;
    rep (i, 1, n) {
        std::cin >> v,
        v == 1 ? pos1 = i : v == 2 ? pos2 = i : v == n ? npos = i : 0;
    }
    if (pos1 < pos2 and pos2 < npos) std::cout << pos2 << ' ' << npos << '\n';
    if (pos1 < npos and npos < pos2) std::cout <<    1 << ' ' <<    1 << '\n';
    if (pos2 < pos1 and pos1 < npos) std::cout << pos1 << ' ' << npos << '\n';
    if (pos2 < npos and npos < pos1) std::cout <<    1 << ' ' <<    1 << '\n';
    if (npos < pos1 and pos1 < pos2) std::cout << pos1 << ' ' << npos << '\n';
    if (npos < pos2 and pos2 < pos1) std::cout << pos2 << ' ' << npos << '\n';
}

int main(void) {
    offsync(); int T; std::cin >> T;
    while (T--) solve();
}