#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e6 + 10;

int n, a[N << 2]; i64 res;

void dfs(int i, int cur, i64 sum) {
    if (i > n) return;
    if (cur > n) return;
    res = std::max(res, sum);
    if ((1 << (i - 1)) > n) return;
    dfs(i + 1, cur, sum);
    dfs(i + 1, cur + (1 << (i - 1)), sum + a[cur + (1 << (i - 1))]);
}

int main(/*int argc, char const* argv[]*/) {
    file("a");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }

    dfs(1, 1, a[1]);

    std::cout << res << '\n';
}