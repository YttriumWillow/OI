#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 25;

int n, a[N][N];
int f[1200010][N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 0, n - 1) rep (j, 0, n - 1) {
        std::cin >> a[i][j];
    }
    memset(f, 0x3f, sizeof f); f[1][0] = 0;
    rep (i, 1, (1 << n) - 1) {
        rep (j, 0, n - 1) if ((i >> j) & 1) {
            rep (k, 0, n - 1) if (((i ^ (1 << j)) >> k) & 1) {
                f[i][j] = std::min(f[i][j], f[i ^ (1 << j)][k] + a[k][j]);
            }
        }
    }
    std::cout << f[(1 << n) - 1][n - 1] << '\n';
}