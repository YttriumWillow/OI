#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 5e5 + 10;
constexpr int inf = 0x7f7f7f7f;
int n, q, v;
int a[N], b[N];
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
struct Box { int val[32], max[32], tot; };
struct Dat {
    int min, max;
    Box prv, suf;
    Dat(int x = 0, int y = 0) {
        prv.val[0] = prv.max[0] = 0; prv.tot = 1;
        suf.val[0] = suf.max[0] = 0; suf.tot = 1;
        prv.max[1] = suf.max[1] = x;
        prv.val[1] = suf.val[1] = y;
        min = y >= v ? x : inf; max = x;
    }
    friend Dat operator + (const Dat& A, const Dat& B) {
        Dat res; int cur;
        res.min = std::min(A.min, B.min), res.max = std::max(A.max, B.max);
        for (int i = A.suf.tot, j = 0; i > 0; --i) {
            while ((A.suf.val[i] | B.prv.val[j]) < v and (j ^ B.prv.tot)) ++j;
            if ((A.suf.val[i] | B.prv.val[j]) >= v) {
                res.min = std::min(res.min, std::max(A.suf.max[i], B.prv.max[j]));
            }
        }
        res.prv.tot = A.prv.tot; res.suf.tot = B.suf.tot;
        rep (i, 1, A.prv.tot) res.prv.val[i] = A.prv.val[i], res.prv.max[i] = A.prv.max[i];
        rep (i, 1, B.suf.tot) res.suf.val[i] = B.suf.val[i], res.suf.max[i] = B.suf.max[i];
        cur = A.prv.val[A.prv.tot]; // int pmax = A.max;
        rep (i, 1, B.prv.tot) if ((cur | B.prv.val[i]) ^ cur) {
            cur = cur | B.prv.val[i];
            ++res.prv.tot; res.prv.val[res.prv.tot] = cur;
            res.prv.max[res.prv.tot] = std::max(A.max, B.prv.max[i]);
        }
        cur = B.suf.val[B.suf.tot]; // int pmax = B.max;
        rep (i, 1, A.suf.tot) if ((cur | A.suf.val[i]) ^ cur) {
            cur = cur | A.suf.val[i];
            ++res.suf.tot; res.suf.val[res.suf.tot] = cur;
            res.suf.max[res.suf.tot] = std::max(B.max, A.suf.max[i]);
        }
        return res;
    }
};
int root, st, ed; Dat A[N << 2];
void build(int u, int l, int r) {
    if (l == r) return A[u] = Dat(a[l], b[l]), void();
    int mid = l + r >> 1;
    build(ls(u), l, mid); build(rs(u), mid + 1, r);
    A[u] = A[ls(u)] + A[rs(u)];
}
void modifyDat(int u, int l, int r, int pos, Dat d) {
    if (l == r) return A[u] = d, void();
    int mid = l + r >> 1;
    if (pos <= mid) modifyDat(ls(u), l, mid, pos, d);
    if (mid < pos) modifyDat(rs(u), mid + 1, r, pos, d);
    A[u] = A[ls(u)] + A[rs(u)];
}
Dat query(int u, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) return A[u];
    int mid = l + r >> 1;
    if (qr <= mid) return query(ls(u), l, mid, ql, qr);
    if (mid < ql)  return query(rs(u), mid + 1, r, ql, qr);
    return query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
}
void init(int _root, int _st, int _ed) {
    root = _root; st = _st; ed = _ed;
    build(root, st, ed);
}
void modifyDat(int pos, int x) {
    modifyDat(root, st, ed, pos, Dat(a[pos], x));
}
int query(int l, int r) {
    int res = query(root, st, ed, l, r).min;
    return res > 1e9 ? -1 : res;
}
int main(/*int argc, char const* argv[]*/) {
    file("eternal"); sync(false, nullptr); 
    std::cin >> n >> q >> v;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) std::cin >> b[i];
    init(1, 1, n);
    while (q--) {
        int o; std::cin >> o;
        // std::cerr << o << '\n';
        if (o == 1) {
            int i, x; std::cin >> i >> x;
            modifyDat(i, x);
        }
        else {
            int k; std::cin >> k;
            std::cout << query(1, n) << '\n';
        }
    }
}