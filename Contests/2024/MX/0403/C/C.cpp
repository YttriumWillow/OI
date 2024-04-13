#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e3 + 10;

int n, m, a[N];
i64 res, f[N][N];

int main(/*int argc, char const* argv[]*/) {
    file("c");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, n) { std::cin >> a[i]; }

    // f[i][j] 表示当前选到第 i 个数，已经选了 j 个数字所得的 value。 

    rep (i, 1, n) {
        f[i][1] = a[i];
        rep (j, 2, n - m) rep (k, 1, i - 1) {
            if (a[k] <= a[i]) {
                f[i][j] = std::max(f[i][j], f[k][j - 1] + a[i]);
            }
        }
        rep (j, 1, n - m) {    
            res = std::max(res, f[i][j]);
        }
    }

    i64 sum = 0;
    rep (i, 1, n) sum += a[i];

    std::cout << sum - res << '\n';
}