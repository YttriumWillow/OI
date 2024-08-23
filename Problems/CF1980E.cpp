#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 2e5 + 5;
int n, m;
int r[N], c[N];

void solve() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> b(n + 1, std::vector<int>(m + 1));
    rep (i, 1, n) rep (j, 1, n) {
        std::cin >> a[i][j];
        r[a[i][j]] = i; c[a[i][j]] = j;
    }   
    rep (i, 1, n) {
        
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}