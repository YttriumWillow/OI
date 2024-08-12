#include <iostream>

#define i64 long long
#define rep(i, l, r) for(int i = l; i <= (r); ++i)

constexpr int N = 505;

int n, m, a[N][N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> m >> n;
    rep (i, 1, n) rep (j, 1, m) {
        std::cin >> a[i][j];
    }

    rep (i, 1, n) rep (j, 1, m) {

    }
}