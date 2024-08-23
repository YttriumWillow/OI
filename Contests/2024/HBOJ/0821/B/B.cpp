#include <bits/stdc++.h>

#define i64 long long
// #define f64 double
#define f64 long double
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;
constexpr f64 inf = 1e18;
constexpr f64 eps = 1e-16;
int n, x[N]; f64 sum, M, res = inf;

f64 check(f64 c) {
    if (c > sum / n) return inf;
    int l = 1, r = n;
    f64 L = c, R = sum / n;
    f64 cur = sum, d = n - 1;
    while (d) {
        if ((cur - x[r]) / d >= c) { cur -= x[r]; --r; --d; }
        else { cur -= x[l]; --d; ++l; R = std::max(R, cur / (d + 1)); }
    }
    return R - L;
}

void run(f64 l, f64 r) {
    while ((r - l) > eps * l) {
        f64 mid1 = (l * 2 / 3) + (r / 3), mid2 = (l / 3) + (r * 2 / 3);
        check(mid1) > check(mid2) ? l = mid1 : r = mid2;
    }
    res = std::min(res, check(l));
}

int main(/*int argc, char const* argv[]*/) {
    // file("seesaw");
    offsync();
    std::cin >> n;
    rep (i, 1, n) std::cin >> x[i];
    rep (i, 1, n) sum += x[i];
    M = sum / n;
    run(M - 1e9, M + 1e9);
    run(M - 1e9, M + 1e8);
    run(0, 1e18);
    run(0, 1e13);
    run(0, 1e9);
    std::cout << std::fixed << std::setprecision(11) << res << '\n';
}