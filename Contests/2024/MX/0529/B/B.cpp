#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define per(i, r, l) for (int i = (r); i >= l; --i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

#define date(p, q) (sum[p - 1] + q)

constexpr int N = 500 + 10;

int sum[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

int n, q, v[N]; std::string T[N];

int main(/*int argc, char const* argv[]*/) {
    file("calendar");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> q;

    rep (i, 1, n) {
        int m, d; std::cin >> m >> d;
        std::cin >> v[date(m, d)] >> T[date(m, d)];
    }

    while (q--) {
        int m1, d1, m2, d2;
        std::cin >> m1 >> d1 >> m2 >> d2;

        int res = 0, id = 0;
        per (i, date(m2, d2), date(m1, d1)) {
            if (v[i] > res) {
                res = v[i]; id = i;
            }
        }
        std::string S = T[id];
        std::cout << (S.empty() ? "Nothing" : S) << '\n';
    }
}