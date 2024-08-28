#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e5 + 5;

int n, X, c[N];

int main(/*int argc, char const* argv[]*/) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    std::cin >> n >> X;
    rep (i, 1, n) { std::cin >> c[i]; c[i] *= (n - i + 1); }
    std::sort(c + 1, c + n + 1);
    int res = 0; rep (i, 1, n) {
        if (X - c[i] >= 0) {
            ++res; X -= c[i];
        }
    }
    std::cout << res << '\n';
}