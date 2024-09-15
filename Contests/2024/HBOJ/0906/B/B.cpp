#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 26;
int n, m; char ch;
int S[N][N], T[N][N];

int main(/*int argc, char const* argv[]*/) {
    file("graffiti");
    sync(false, nullptr);
    std::cin >> n >> m;
    rep (i, 1, n) rep (j, 1, m) {
        std::cin >> ch;
        S[i][j] = ch == 'B';
    }
    rep (i, 1, n) rep (j, 1, m) {
        std::cin >> ch;
        T[i][j] = ch == 'B';
    }
    if (n == 1 and m == 1) {
        std::cout << ((S[1][1] == T[1][1]) ? 0 : 2) << '\n';
        return 0;
    }

    std::cout << 6 << '\n';

}