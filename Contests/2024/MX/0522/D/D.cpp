#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e6 + 10;
constexpr int LG = 30 + 10;

int n, q, a[N], b[N], pos[N];
int tot, l[N], r[N];

namespace ST {
    int st[N][LG], lg2[N];
    inline void init(int n) { lg2[1] = 0;
        rep (i, 2, n) lg2[i] = lg2[i >> 1] + 1;
        rep (i, 1, n) st[i][0] = r[i] - l[i];
        for (int j = 1; (1 << j) <= n; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r) {
        int k = lg2[r - l + 1];
        return std::min(st[l][k], st[r - (1 << k) + 1][k]);
    }
} using namespace ST;

int main(/*int argc, char const* argv[]*/) {
    file("dis");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> q;
    rep (i, 1, n) { std::cin >> a[i]; b[i] = a[i]; }

    std::sort(b + 1, b + n + 1); int siz = std::unique(b + 1, b + n + 1) - b - 1;
    rep (i, 1, n) { a[i] = std::lower_bound(b + 1, b + siz + 1, a[i]) - b; }

    rep (i, 1, n) {
        int x = pos[a[i]];
        if (x > l[tot]) {
            l[++tot] = x; r[tot] = i;
        }
        pos[a[i]] = i;
    }

    init(tot);

    while (q--) {
        int x, y; std::cin >> x >> y;
        x = std::lower_bound(l + 1, l + tot + 1, x) - l;
        y = std::upper_bound(r + 1, r + tot + 1, y) - r - 1;
        std::cout << (x <= y ? query(x, y) : -1) << '\n';
    }

}