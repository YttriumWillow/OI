#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout); std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], b[N];
int l[N], r[N];
i64 sum[N], res = -inf;

void _0() {
    i64 res = -inf, d = inf;
    rep (i, 1, n) {
        sum[i] = sum[i - 1] + a[i];
        d = std::min(d, sum[i - 1]);
        res = std::max(res, sum[i] - d);
    }
    std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    file("swap");

    std::cin >> n >> k;
    rep (i, 1, n) std::cin >> a[i];
    if (k == 0) { _0(); return 0; }
    rep (i, 1, n) sum[i] = sum[i - 1] + a[i];
    rep (i, 1, n) rep (j, i, n) {
        rep (t, i, j) {
            b[t] = a[t];
        }
        sort(b + i, b + j + 1, std::greater<int>());
        i64 val = sum[j] - sum[i - 1];
        rep (t, 1, k) {
            val -= b[i + t - 1];
        }
        res = std::max(res, val);
    }
    std::cout << res;
}