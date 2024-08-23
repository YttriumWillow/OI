#include <bits/stdc++.h>

#define int long long
#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 2e5 + 5;
constexpr int L = -2e6, R = 2e6;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

int n, l = inf, r = -inf; i64 D;
int x[N]; i64 prvX[N], sufX[N]; std::vector<i64> X;
int y[N]; i64 prvY[N], sufY[N]; std::vector<i64> Y;

signed main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> D;
    rep (i, 1, n) std::cin >> x[i] >> y[i];
    std::sort(x + 1, x + n + 1);
    std::sort(y + 1, y + n + 1);
    rep (i, 1, n) {
        prvX[i] = prvX[i - 1] + x[i];
        prvY[i] = prvY[i - 1] + y[i];
    }
    for (int i = n; i >= 1; --i) {
        sufX[i] = sufX[i + 1] + x[i];
        sufY[i] = sufY[i + 1] + y[i];
    }
    int k; rep (i, L, R) {
        k = std::upper_bound(x + 1, x + n + 1, i) - x;
        X.push_back(i * (k - 1) - prvX[k - 1] + sufX[k] - i * (n - k + 1));
        k = std::upper_bound(y + 1, y + n + 1, i) - y;
        Y.push_back(i * (k - 1) - prvY[k - 1] + sufY[k] - i * (n - k + 1));
    }
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end()); Y.push_back(inf);
    i64 res = 0; for (auto i : X) {
        if (D - i < 0) continue;
        res += std::upper_bound(Y.begin(), Y.end(), D - i) - Y.begin();
    }
    std::cout << res << '\n';
}