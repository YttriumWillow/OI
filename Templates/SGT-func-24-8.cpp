#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout); std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) { }
} P[N];
int n;
Point a[N];
i64 f[1005][1005];

template<typename _Tp> class SGT {
private:
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
    static constexpr int L = 2e5 + 5;
    _Tp Min[N << 2], tag[N << 2];
    int root, st, ed;
    void build(int u, int l, int r) {
        if (l == r) return Min[u] = inf, void();
        int mid = (l + r) >> 1;
        build(ls(u), l, mid); build(rs(u), mid + 1, r);
        Min[u] = std::min(Min[ls(u)], Min[rs(u)]);
    }
    void modifyTag(int u, _Tp val) {
        Min[u] += val; tag[u] += val;
    }
    void pushDown(int u) {
        if (tag[u]) {
            modifyTag(ls(u), tag[u]); modifyTag(rs(u), tag[u]);
            tag[u] = 0;
        }
    }
    void modifySet(int u, int l, int r, int pos, _Tp val) {
        if (l == r) return Min[u] = val, void();
        int mid = (l + r) >> 1; pushDown(u);
        if (pos <= mid) modifySet(ls(u), l, mid, pos, val);
        if (mid < pos)  modifySet(rs(u), mid + 1, r, pos, val);
        Min[u] = std::min(Min[ls(u)], Min[rs(u)]);
    }
    void modifyAdd(int u, int l, int r, int ql, int qr, _Tp val) {
        if (ql > qr) return;
        if (ql <= l and r <= qr) return modifyTag(u, val);
        int mid = (l + r) >> 1; pushDown(u);
        if (ql <= mid) modifyAdd(ls(u), l, mid, ql, qr, val);
        if (mid < qr)  modifyAdd(rs(u), mid + 1, r, ql, qr, val);
        Min[u] = std::min(Min[ls(u)], Min[rs(u)]);
    }
    _Tp query(int u, int l, int r, int ql, int qr) {
        if (ql > qr) return inf;
        if (ql <= l and r <= qr) return Min[u];
        int mid = (l + r) >> 1; _Tp ret = inf; pushDown(u);
        if (ql <= mid) ret = std::min(ret, query(ls(u), l, mid, ql, qr));
        if (mid < qr)  ret = std::min(ret, query(rs(u), mid + 1, r, ql, qr));
        Min[u] = std::min(Min[ls(u)], Min[rs(u)]); return ret;
    }
public:
    SGT(int _root = 1, int _st = 1, int _ed = 1) {
        root = _root; st = _st; ed = _ed;
        build(root, st, ed);
    }
    void modifySet(int pos, _Tp val) {
        modifySet(root, st, ed, pos, val);
    }
    void modifyAdd(int l, int r, _Tp val) {
        modifyAdd(root, st, ed, l, r, val);
    }
    _Tp query(int l, int r) {
        return query(root, st, ed, l, r);
    }
};

int main(/*int argc, char const* argv[]*/) {
    
}