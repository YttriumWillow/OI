#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 4e5 + 5;

int n, m, k; i64 res;
int lx[N], ly[N], lnx[N];

#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
int sum[N << 2]; i64 len[N << 2];
void pushup(int u, int l, int r) {
    sum[u] ? len[u] = lnx[r + 1] - lnx[l] : len[u] = len[ls(u)] + len[rs(u)];
}
void modifyAdd(int u, int l, int r, int ql, int qr, int val) {
    if (lnx[r + 1] <= ql || lnx[l] >= qr) return;
    if (ql <= lnx[l] and lnx[r + 1] <= qr) {
        sum[u] += val; pushup(u, l, r); return;
    }
    int mid = (l + r) >> 1;
    if (ql <= lnx[r + 1]) modifyAdd(ls(u), l, mid, ql, qr, val);
    if (lnx[l] < qr)      modifyAdd(rs(u), mid + 1, r, ql, qr, val);
    pushup(u, l, r);
}
i64 query() { return len[1]; }
struct _ {
    int l, r, y, v;
    friend bool operator < (const _& A, const _& B) { return A.y < B.y; }
} ln[N << 2]; int tot;

int main(/*int argc, char const* argv[]*/) {
    file("obstacle");
    offsync(); std::cin >> n >> m >> k;
    int r = std::max(m, n);
    rep (i, 1, r) {
        lx[i] = n + 1;
        ly[i] = m + 1;
    }
    rep (i, 1, k) {
        int x, y; std::cin >> x >> y;
        lx[y] = std::min(lx[y], x);
        ly[x] = std::min(ly[x], y);
    }
    rep (i, 1, lx[1] - 1) {
        ++tot;
        ln[tot * 2 - 1] = { i, i + 1, 1, 1 };
        ln[tot * 2] = { i, i + 1, ly[i], -1 };
        lnx[tot * 2 - 1] = i; lnx[tot * 2] = i + 1;
    }
    rep (i, 1, ly[1] - 1) {
        ++tot;
        ln[tot * 2 - 1] = { 1, lx[i], i, 1 };
        ln[tot * 2] = { 1, lx[i], i + 1, -1 };
        lnx[tot * 2 - 1] = 1; lnx[tot * 2] = lx[i];
    }
    tot *= 2;
    std::sort(ln + 1, ln + tot + 1);
    std::sort(lnx + 1, lnx + tot + 1);
    int siz = std::unique(lnx + 1, lnx + tot + 1) - lnx - 1;
    rep (i, 1, tot - 1) {
        modifyAdd(1, 1, siz - 1, ln[i].l, ln[i].r, ln[i].v);
        res += query() * (ln[i + 1].y - ln[i].y);
    }
    std::cout << res << '\n';
}
