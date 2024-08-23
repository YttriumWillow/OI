#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e5 + 5;
using i64 = long long;
using f64 = double;
int n, m;
class SGT {
private:
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
    static constexpr int N = ::N << 2;
    f64 max[N]; int len[N]; int root, st, ed;
    int calc(int u, int l, int r, f64 val) {
        int mid = l + r >> 1;
        if (max[u] <= val) return 0;
        if (l == r) return max[u] > val;
        if (max[ls(u)] <= val) return calc(rs(u), mid + 1, r, val);
        return calc(ls(u), l, mid, val) + len[u] - len[ls(u)];
    }
    void modifySet(int u, int l, int r, int pos, f64 val) {
        if (l == r) return max[u] = val, len[u] = 1, void();
        int mid = l + r >> 1;
        if (pos <= mid) modifySet(ls(u), l, mid, pos, val);
        if (mid < pos)  modifySet(rs(u), mid + 1, r, pos, val);
        max[u] = std::max(max[ls(u)], max[rs(u)]);
        len[u] = calc(rs(u), mid + 1, r, max[ls(u)]) + len[ls(u)];
    }
public:
    SGT(int _root = 1, int _st = 1, int _ed = 1) : root(_root), st(_st), ed(_ed) { }
    void modifySet(int pos, f64 val) {
        modifySet(root, st, ed, pos, val);
    }
    int query() { return len[root]; }
};

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n >> m;
    SGT T(1, 1, n);
    rep (i, 1, m) {
        int x, y; std::cin >> x >> y;
        T.modifySet(x, 1.0 * y / x);
        std::cout << T.query() << '\n';
    }
}