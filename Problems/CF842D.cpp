#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 3e5 + 5;

class _01trie {
    int t[N * 32][2], siz[N * 32], cnt = 1;
public:
    void insert(int x, int p = 20, int u = 1) {
        if (!~p) return siz[u] = 1, void();
        int v = (x >> p) & 1;
        if (!t[u][v]) t[u][v] = ++cnt;
        insert(x, p - 1, t[u][v]);
        siz[u] = siz[t[u][0]] + siz[t[u][1]];
    }
    int query(int x) {
        int u = 1, res = 0;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            if (siz[t[u][v]] == (1 << i)) {
                u = t[u][v ^ 1];
                res |= 1 << i;
            }
            else u = t[u][v];
            if (!u) return res;
        }
        return res;
    }
};

int n, m, a[N]; _01trie T;

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, n) {
        std::cin >> a[i];
        T.insert(a[i]);
    }
    int cur = 0;
    while (m--) {
        int x; std::cin >> x; cur ^= x;
        std::cout << T.query(cur) << '\n';
    }
}