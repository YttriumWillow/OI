#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

int n, A, B, c1, c2;
i64 sum, res;
i64 v[52], C[52][52];

void init(int N = 50) {
    rep (i, 0, N) C[i][0] = 1;
    rep (i, 1, N) rep (j, 1, i) {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr); std::cin >> n >> A >> B; init();
    rep (i, 1, n) std::cin >> v[i];
    std::sort(v + 1, v + n + 1, std::greater<i64>());
    rep (i, 1, A) sum += v[i];
    rep (i, 1, n) if (v[i] == v[A]) ++c1;
    rep (i, 1, A) if (v[i] == v[A]) ++c2;
    if (v[1] == v[A])
        rep (i, A, B) res += C[c1][i];
    else res = C[c1][c2];
    std::cout << std::fixed << std::setprecision(10) << 1.0 * sum / A << '\n';
    std::cout << res << '\n';

}