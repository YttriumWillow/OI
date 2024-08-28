#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e6 + 5;

int n, m;
int tag[N][21];
int tim[N][21];

int main() {
    std::cin >> n >> m;
    rep (i, 1, m) {
        int op; std::cin >> op;
        if (op == 1) {
            int x, y, z; std::cin >> x >> y >> z;
            while (x && y >= 0) {
                tag[x][std::min(y, 20)] = z;
                tim[x][std::min(y, 20)] = i;
                x >>= 1; --y;
            }
        }
        else {
            int x = 0, y = 0; int t = 0, res = 0;
            std::cin >> x;
            while (x) {
                rep (j, y, 20) if (tim[x][j] > t)
                    t = tim[x][j], res = tag[x][j];
                x >>= 1; ++y;
            }
            std::cout << res << '\n';
        }
    }
}