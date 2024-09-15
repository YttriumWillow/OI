#include <bits/stdc++.h>

#define i64 long long
#define rep(i, a, b) for (int i = (a); i <= b; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 5e5 + 5;
constexpr int M = 2e6 + 5;

int n, q, x[N], y[N], b[N];

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
std::array<int, 4> qry[M]; // Queries
BIT T; int cnt, ret[M];

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> t[i] >> y[i];
    std::sort(t + 1, t + n + 1);
    rep (i, 1, n)
        x[i] = std::lower_bound(t + 1, t + n + 1, t[i]) - t;
    rep (i, 1, n) p[i] = { x[i], y[i] };

    rep (i, 1, q) {
        int a, b, c, d; std::cin >> a >> b >> c >> d;
        a = std::lower_bound(t + 1, t + n + 1, a) - t;
        c = std::lower_bound(t + 1, t + n + 1, c) - t;
        ++cnt; qry[cnt] = { c, d, cnt, 1 };
        ++cnt; qry[cnt] = { c, b - 1, cnt, 1 };
        ++cnt; qry[cnt] = { a - 1, d, cnt, 1 };
        ++cnt; qry[cnt] = { a - 1, b - 1, cnt, 1 };
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