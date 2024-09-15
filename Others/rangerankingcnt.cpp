#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 4e5 + 5;
constexpr int M = 4e5 + 5;
int n, q, a[N], b[N];

struct BIT {
#define lowbit(x) ((x) & -(x))
    static constexpr int N = ::N;
    int v[N];
    void add(int i, int k) {
        for (; i <= N; i += lowbit(i)) v[i] += k;
    }
    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i)) res += v[i];
        return res;
    }
};

// x, y
std::array<int, 2> p[N]; // Points
// x, y, id, w
std::array<int, 4> qry[N]; // Queries
BIT T; int cnt, ret[N];

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> b[i], a[i] = b[i];

    std::sort(b + 1, b + n + 1);
    rep (i, 1, n)
        a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;

    rep (i, 1, n) p[i] = { i, a[i] };

    rep (i, 1, q) {
        int l, r, s, t; std::cin >> l >> s >> r >> t;
        ++cnt; qry[cnt] = { s, t, cnt, 1 };
        ++cnt; qry[cnt] = { s, r - 1, cnt, 1 };
        ++cnt; qry[cnt] = { l - 1, t, cnt, 1 };
        ++cnt; qry[cnt] = { l - 1, r - 1, cnt, 1 };
    }
    std::sort(p + 1, p + n + 1);
    std::sort(qry + 1, qry + cnt + 1);
    int now = 1;
    rep (i, 1, cnt) {
        while (p[now][0]/*x*/ <= qry[i][0]/*x*/ and now <= n) {
            T.add(p[now][1] + 1, 1); ++now;
        }
        ret[qry[i][2]/*id*/] += T.query(qry[i][1]/*y*/ + 1);
    }
    for (int i = 1; i <= cnt; i += 4) {
        std::cout << ret[i] - ret[i + 1] - ret[i + 2] + ret[i + 3] << '\n';
    }
}