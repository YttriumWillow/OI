#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 10;
int n, d, a[N], b[N], c[N];
int L = 1e9 + 1, R; i64 res;

void Task_1() { // 朴素暴力
    rep (l, L, R - d) {
        int r = l + d; i64 sum = 0;
        rep (i, 2, n) {
            int x = a[i - 1], y = a[i];
            x = (x < l) ? l : ((x > r) ? r : x);
            y = (y < l) ? l : ((y > r) ? r : y);
            sum += std::abs(x - y);
        }
        res = std::max(res, sum);
    }
    std::cout << res << '\n';
}

i64 check(int c) {
    int l = c, r = c + d; i64 sum = 0;
    rep (i, 2, n) {
        int x = a[i - 1], y = a[i];
        x = (x < l) ? l : ((x > r) ? r : x);
        y = (y < l) ? l : ((y > r) ? r : y);
        sum += std::abs(x - y);
    }
    res = std::max(res, sum); return sum;
}

void Task_2() { // 值域上三分
    int l = L, r = R - d;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3; i64 v1 = check(m1);
        int m2 = r - (r - l) / 3; i64 v2 = check(m2);
        v1 >= v2 ? r = m2 : l = m1;
        // std::cerr << "l=" << l << ",r=" << r << '\n';
        // std::cerr << "m1=" << m1 << ",c(m1)" << check(m1) << '\n';
        // std::cerr << "m2=" << m2 << ",c(m2)" << check(m2) << '\n';
    }
    std::cout << std::max({ res, check(l), check(l + 1), check(r) }) << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    file("goods"); sync(false, nullptr);
    std::cin >> n >> d;
    rep (i, 1, n) {
        std::cin >> a[i]; b[i] = c[i] = a[i];
        L = std::min(L, a[i]);
        R = std::max(R, a[i]);
    }

    if (R <= 10) return Task_1(), 0;
    return Task_2(), 0;
}