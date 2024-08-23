#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 6e4 + 5;
constexpr double eps = 1e-6;

int n, x[N], v[N];

bool check(double c) {
    double max = 0, min = 1e9;
    rep (i, 1, n) {
        max = std::max(max, 1.0 * x[i] - v[i] * c); 
        min = std::min(min, 1.0 * x[i] + v[i] * c);
    }
    return max <= min;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) std::cin >> x[i];
    rep (i, 1, n) std::cin >> v[i];
    double l = 1e-7, r = 1e9 + 1;
    while (r - l > eps) {
        auto mid = (l + r) / 2;
        check(mid) ? r = mid : l = mid;
    }
    std::cout << std::fixed << std::setprecision(12) << l << '\n';
}