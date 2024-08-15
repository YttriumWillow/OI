#include <iostream>
#include <algorithm>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 4e5 + 5;
int n, m, len, l[N], r[N];
struct Seg {
    int x, y;
    friend bool operator < (const Seg& A, const Seg& B) {
        return A.x ^ B.x ? A.x < B.x : A.y > B.y;
    }
} a[N];

template<typename _Tp>
class SGT {
private:
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
    static constexpr int L = 4e5 + 5;
    static constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
    _Tp Max[L << 4], tag[L << 4];
    int root, st, ed;
    void modifyTag(int u, _Tp val) {
        Max[u] += val; tag[u] += val;
    }
    void pushDown(int u) {
        if (tag[u]) { modifyTag(ls(u), tag[u]); modifyTag(rs(u), tag[u]); tag[u] = 0; }
    }
    void build(int u, int l, int r) {
        if (l == r) return Max[u] = tag[u] = 0, void();
        int mid = (l + r) >> 1;
        build(ls(u), l, mid); build(rs(u), mid + 1, r);
        Max[u] = std::max(Max[ls(u)], Max[rs(u)]);
    }
    void modifyAdd(int u, int l, int r, int ql, int qr, _Tp val) {
        if (ql > qr) return;
        if (ql <= l and r <= qr) return modifyTag(u, val);
        int mid = (l + r) >> 1; pushDown(u);
        if (ql <= mid) modifyAdd(ls(u), l, mid, ql, qr, val);
        if (mid < qr)  modifyAdd(rs(u), mid + 1, r, ql, qr, val);
        Max[u] = std::max(Max[ls(u)], Max[rs(u)]);
    }
    _Tp query(int u, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l and r <= qr) return Max[u];
        int mid = (l + r) >> 1; _Tp ret = inf; pushDown(u);
        if (ql <= mid) ret = std::max(ret, query(ls(u), l, mid, ql, qr));
        if (mid < qr)  ret = std::max(ret, query(rs(u), mid + 1, r, ql, qr));
        Max[u] = std::max(Max[ls(u)], Max[rs(u)]); return ret;
    }
public:
    SGT(int _root = 1, int _st = 1, int _ed = 1) {
        root = _root; st = _st; ed = _ed;
        // build(root, st, ed);
    }
    void modifyAdd(int l, int r, _Tp val) {
        modifyAdd(root, st, ed, l, r, val);
    }
    _Tp query(int l, int r) {
        return query(root, st, ed, l, r);
    }
};

int main(/*int argc, char const* argv[]*/) {
    file("mermaid");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i].x >> a[i].y;
    std::sort(a + 1, a + n + 1);
    int R = 0; rep (i, 1, n)
    if (R < a[i].y) {
        l[++len] = a[i].x; r[len] = a[i].y;
        R = a[i].y;
    }
    SGT<i64> T(1, 1, len);
    rep (i, 1, m) {
        int p, x; std::cin >> p >> x;
        int ql = std::lower_bound(r + 1, r + len + 1, p) - r;
        int qr = std::upper_bound(l + 1, l + len + 1, p) - l - 1;
        if (ql <= qr) T.modifyAdd(ql, qr, x);
        std::cout << T.query(1, len) << '\n';
    }

    return 0;
}