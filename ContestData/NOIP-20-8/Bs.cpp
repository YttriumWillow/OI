#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mp make_pair
#define pb emplace_back
#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
#define pv(a) cout << #a << " = " << a << endl
#define pa(a, l, r) cout << #a " : "; rep(_, l, r) cout << a[_] << ' '; cout << endl

using db = double;
using pdd = pair <db, db>;

const int N = 1e6 + 10;

int read() {
    int x = 0, f = 1; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = -1;
    for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
    return x * f;
}

int n, a[N];
db g, ans = 1e18;
pdd rg[N];

signed main() {
    n = read();
    rep(i, 1, n) a[i] = a[i - 1] + read();
    g = (db)a[n] / n;
    for (int i = 1, p = n; i < n; ++i) {
        while (p + i - 1 > n || (db)(a[p + i - 1] - a[p - 1]) / i > g) --p;
        rg[i].first = (db)(a[p + i - 1] - a[p - 1]) / i;
        rg[i].second = (db)(a[p + i] - a[p]) / i;
    }
    sort(rg + 1, rg + n);
    db mx = g;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, mx - rg[i].first);
        mx = max(mx, rg[i].second);
    }
    printf("%.10lf\n", ans);
    return 0;
}