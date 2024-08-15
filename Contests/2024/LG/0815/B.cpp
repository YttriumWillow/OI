#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e6 + 5;
constexpr int LOG = 25;

int n, k, a[N], b[N];
int st[N][LOG];
inline int query(int l, int r) {
    int z = std::__lg(r - l + 1);
    return std::max(st[l][z], st[r - (1 << z) + 1][z]);
}

void f5() {
    rep (i, 1, k)  rep (j, 1, n - i) {
        a[j] = std::max(a[j], a[j + 1]);
    }
    rep (i, k + 1, n) rep (j, 1, n - i) {
        a[j] = std::min(a[j], a[j + 1]);
    }
    std::cout << a[1] << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> k;

    rep (i, 1, n) { std::cin >> a[i]; st[i][0] = a[i]; }

    if (n <= 5000) { f5(); return 0; }

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    int res = 0x7f7f7f7f;
    rep (i, 1, n) {
        // int ql = std::max(i - k, 1);
        int ql = i;
        int qr = std::min(i + k, n);
        b[i] = query(ql, qr);
    }

    rep (i, 1, n - k) res = std::min(res, b[i]);

    std::cout << res << '\n';
}