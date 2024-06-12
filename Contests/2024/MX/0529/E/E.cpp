#include <iostream>
#include <algorithm>
#include <cstring>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define per(i, r, l) for (int i = (r); i >= l; --i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 10;
constexpr i64 inf = 0x7f7f7f7f7f7f7f7f;

struct Trie {
    int tot, ch[N * 64][2];
    Trie() { tot = 1; memset(ch, 0, sizeof ch); }
    void insert(i64 v) {
        int u = 1;
        per (i, 59, 0) {
            int c = ((v >> i) & 1);
            if (not ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
    }
    i64 query(i64 v) {
        i64 res = 0;
        int u = 1;
        per (i, 59, 0) {
            int c = ((v >> i) & 1);
            if (ch[u][c]) u = ch[u][c];
            else {
                res |= (1ll << i);
                u = ch[u][c ^ 1];
            }
        }
        return res;
    }
} T;

int n; i64 a[N];
i64 res = inf;

int main(/*int argc, char const* argv[]*/) {
    // file("msc");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }

    std::sort(a + 1, a + n + 1);

    int bMax = -1;
    per (i, 59, 0) {
        if (((a[1] ^ a[n]) >> i) & 1) {
            bMax = i; break;
        }
    }

    if (!~bMax) {
        std::cout << 0 << '\n'; return 0;
    }

    rep (i, 1, n) {
        (a[i] >> bMax) & 1 ? (void)(res = std::min(res, T.query(a[i]))) : T.insert(a[i]);
    }

    std::cout << res << '\n';
}