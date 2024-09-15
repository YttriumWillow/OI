#include <bits/stdc++.h>

const int maxn = 1e3;

int a[maxn + 1][maxn + 1], f[maxn + 1][maxn + 1], g[maxn + 1][maxn + 1], pre[maxn + 1][maxn + 1],
    suf[maxn + 1][maxn + 1];

int main() {
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) std::cin >> a[i][j];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= i; ++j) {
            f[i][j] += a[i][j];
            f[i + 1][j] = std::max(f[i + 1][j], f[i][j]);
            f[i + 1][j + 1] = std::max(f[i + 1][j + 1], f[i][j]);
        }

    for (int i = 1; i <= n; ++i) {
        f[n][i] += a[n][i];
        g[n][i] = a[n][i];
    }
    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j) g[i][j] = std::max(g[i + 1][j], g[i + 1][j + 1]) + a[i][j];

    for (int i = 1; i <= n; ++i) pre[n][i] = std::max(pre[n][i - 1], f[n][i]);
    suf[n][n] = f[n][n];
    for (int i = n - 1; i >= 1; --i) suf[n][i] = std::max(suf[n][i + 1], f[n][i]);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) f[i][j] += std::max(g[i + 1][j], g[i + 1][j + 1]);
        for (int j = 1; j <= i; ++j) pre[i][j] = std::max(pre[i][j - 1], f[i][j]);
        suf[i][i] = f[i][i];
        for (int j = i - 1; j >= 1; --j) suf[i][j] = std::max(suf[i][j + 1], f[i][j]);
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;

        if (x == 1 && y == 1)
            std::cout << -1 << std::endl;
        else
            std::cout << std::max(pre[x][y - 1], suf[x][y + 1]) << std::endl;
    }
    return 0;
}
