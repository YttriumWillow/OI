#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e3 + 10;
constexpr int P = 1e4;

int n, k, f[N][N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> k;
    f[1][0] = 1;
    rep (i, 2, n) {
        int sum = 0; rep (j, 0, k) {
            f[i][j] = sum = sum + (f[i - 1][j] % P) % P;
            if (j >= i - 1)
                sum = ((sum - f[i - 1][j - i + 1]) % P + P) % P;
        }
    } 
    std::cout << f[n][k] % P << '\n';
}