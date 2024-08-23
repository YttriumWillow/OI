#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

using i64 = long long;
using f64 = double;
constexpr int N = 2e5 + 5;

struct T {
    f64 ave; int l, r;
    friend bool operator < (const T &A, const T& B) { return A.ave > B.ave; }
};
int n, a[N]; i64 sum[N];
std::priority_queue<T> Q;

f64 ave(int l, int r) { return 1.0 * (sum[r] - sum[l - 1]) / (f64)(r - l + 1); }

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) sum[i] = sum[i - 1] + a[i];
    f64 c = ave(1, n); int l = 1, r = n;
    while (1) {
        Q.push({ ave(l, r), l, r });
        if (r == l) break;
        (ave(l + 1, r) <= c) ? (++l) : (--r);
    }
    f64 res = 2e9, max = c;
    while (!Q.empty()) {
        int ls = Q.top().l, rs = Q.top().r; f64 aves = Q.top().ave;
        f64 rng = max - aves; res = std::min(res, rng);
        if (rs == n) break;
        Q.pop(); Q.push({ ave(ls + 1, rs + 1), ls + 1, rs + 1 });
        max = std::max(max, ave(ls + 1, rs + 1));
    }
    std::cout << std::fixed << std::setprecision(10) << res << '\n';
}
