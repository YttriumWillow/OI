#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
constexpr int N = 2e5 + 5;

i64 n, q, blood, a[N];

// standard SGT
template<typename _Tp> class SGT {
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
    static constexpr int N = ::N << 2;
    _Tp sum[N], tag[N]; int rt, st, ed;
    void build(int u, int l, int r) {
        if (l == r) return sum[u] = a[l], void();
        int mid = l + r >> 1;
        build(ls(u), l, mid); build(rs(u), mid + 1, r);
        sum[u] = sum[ls(u)] + sum[rs(u)];
    }
    void modifyTag(int u, int l, int r, _Tp v) {
        sum[u] += v * (r - l + 1); tag[u] += v;
    }
    void pushDown(int u, int l, int r) {
        if (!tag[u]) return;
        int mid = l + r >> 1;
        modifyTag(ls(u), l, mid, tag[u]);
        modifyTag(rs(u), mid + 1, r, tag[u]);
        tag[u] = 0;
    }
    void modifyAdd(int u, int l, int r, int ql, int qr, _Tp v) {
        if (ql > qr) return;
        if (ql <= l and r <= qr) return modifyTag(u, l, r, v);
        int mid = l + r >> 1; pushDown(u, l, r);
        if (ql <= mid) modifyAdd(ls(u), l, mid, ql, qr, v);
        if (mid <  qr) modifyAdd(rs(u), mid + 1, r, ql, qr, v);
        sum[u] = sum[ls(u)] + sum[rs(u)];
    }
    _Tp query(int u, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l and r <= qr) return sum[u];
        int mid = l + r >> 1; _Tp res = 0; pushDown(u, l, r);
        if (ql <= mid) res += query(ls(u), l, mid, ql, qr);
        if (mid <  qr) res += query(rs(u), mid + 1, r, ql, qr);
        sum[u] = sum[ls(u)] + sum[rs(u)]; return res;
    }
    int find(int u, int l, int r, _Tp rem, int pw) {
        if (l == r) return 1ll * sum[u] * pw >= rem ? l - 1 : l;
        pushDown(u, l, r);
        int mid = l + r >> 1; _Tp res = 0;
        if (1ll * sum[ls(u)] * pw < rem)
            res = find(rs(u), mid + 1, r, rem - 1ll * sum[ls(u)] * pw, pw);
        else 
            res = find(ls(u), l, mid, rem, pw);
        sum[u] = sum[ls(u)] + sum[rs(u)]; return res;
    }
public:
    SGT(int r = 1, int s = 1, int t = 1) {
        rt = r, st = s, ed = t;
        build(rt, st, ed);
    }
    void modifyAdd(int l, int r, _Tp v) {
        modifyAdd(rt, st, ed, l, r, v);
    }
    _Tp query(int l, int r) {
        return query(rt, st, ed, l, r);
    }
    _Tp operator[](int i) { return sum[i]; }
    int find(_Tp rem, int pw) {
        return find(rt, st, ed, rem, pw);
    }
};

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    std::cin >> n >> q >> blood;
    rep (i, 1, n) std::cin >> a[i];
    SGT<i64> T(1, 1, n);
    while (q--) {
        i64 l, r, d; std::cin >> l >> r >> d;
        T.modifyAdd(l, r, d);
        i64 S = T[1], rem = blood, res = 0, pw = 1;
        while (rem > S) {
            rem -= S; res += n; S <<= 1; pw <<= 1;
        }
        std::cout << (i64)(res + T.find(rem, pw)) << '\n';
    }
}