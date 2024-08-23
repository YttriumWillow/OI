#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3fll;

int n, tot, a[N];
i64 sum, res, prt[N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> a[1]; res = a[1];
    rep (i, 2, n) {
        char p; std::cin >> p >> a[i];
        a[i] *= (p == '+') ? 1 : -1;
        res = res + a[i];
    }

    tot = 1; rep (i, 1, n) {
        if (a[i - 1] >= 0 and a[i] >= 0)
            prt[tot] += a[i]; // merge continuous positive numbers
        else
            prt[++tot] = a[i]; // 
    }

    rep (i, 1, tot) sum += std::abs(prt[i]); // all to positive

    rep (i, 2, tot) {
        if (prt[i - 1] < 0 and prt[i] >= 0) {
            res = std::max(res, sum + 2 * (prt[i - 1] - prt[i]));
            sum += 2 * prt[i - 1];
        }
        if (prt[i - 1] < 0 and prt[i] < 0) {
            res = std::max(res, sum + 2 * (prt[i - 1]));
            sum += 2 * prt[i - 1];
        }
    }

    std::cout << res << '\n';

}