#include <iostream>
#include <algorithm>
#include <cmath>

#define u32 unsigned int
#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int inf = 0x3f3f3f3f;

int n, A[15][5], f[1 << 12];

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;
    rep (i, 0, n - 1) {
        std::cin >> A[i][0] >> A[i][1] >> A[i][2];
        --A[i][0]; --A[i][1]; --A[i][2];
    }

    f[0] = 0;
    rep (S, 1, (1 << n) - 1) {
        int cnt = 0;
        rep (i, 0, n - 1)
            if (S & (1 << i))
                cnt += 3 - (((S >> A[i][0]) & 1) + ((S >> A[i][1]) & 1) + ((S >> A[i][2]) & 1));
        f[S] = inf;
        rep (i, 0, n - 1) {
            if (S & (1 << i)) {
                int v = cnt - 3 + 2 * (((S >> A[i][0]) & 1) + ((S >> A[i][1]) & 1) + ((S >> A[i][2]) & 1));
                f[S] = std::min(f[S], f[S & ~(1 << i)] + v);
            }
        }
    }
    std::cout << f[(1 << n) - 1] << '\n';
}
