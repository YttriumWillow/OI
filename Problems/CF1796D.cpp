#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 2e5 + 5;

int n, k, x, a[N];
int f[N][N][25];
void solve() {
    std::cin >> n >> k >> x;
    rep (i, 1, n) std::cin >> a[i];
    // set f[i][j] 
    rep (i, 1, n) {
        rep (j, 1, n) {

        }
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}