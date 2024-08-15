#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int maxn = 1e5 + 5;
const int B = 320;
int n, m;
int a[maxn], b[maxn], tot;
int tong[maxn];
int cnt[maxn];
int large[maxn], num, rnk[maxn];
ll s[maxn][B + 5], t[B + 5][maxn];
vector<int> g[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    sort(b + 1, b + 1 + n);
    tot = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
    for (int i = 1; i <= n; i++)
        g[a[i]].push_back(i);
    for (int i = 1; i <= n; i++)
        tong[a[i]]++;
    for (int i = 1; i <= tot; i++)
        if (tong[i] >= B)
            large[++num] = i, rnk[i] = num;
    for (int i = 1; i <= n; i++) {
        ++cnt[a[i]];
        for (int j = 1; j <= num; j++)
            s[a[i]][j] = max(s[a[i]][j], 1ll * cnt[a[i]] * (tong[large[j]] - cnt[large[j]]));
    }
    for (int i = 1; i <= tot; i++)
        cnt[i] = 0;
    for (int i = n; i >= 1; i--) {
        ++cnt[a[i]];
        for (int j = 1; j <= num; j++)
            t[j][a[i]] = max(t[j][a[i]], 1ll * cnt[a[i]] * (tong[large[j]] - cnt[large[j]]));
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        x = lower_bound(b + 1, b + 1 + tot, x) - b;
        y = lower_bound(b + 1, b + 1 + tot, y) - b;
        if (x == y)
            cout << 1ll * (tong[x] / 2) * (tong[x] - tong[x] / 2) << endl;
        else if (tong[x] >= B)
            cout << t[rnk[x]][y] << endl;
        else if (tong[y] >= B)
            cout << s[x][rnk[y]] << endl;
        else {
            int yp = 0, num = 0;
            ll ans = 0;
            for (int i : g[x]) {
                ++num;
                while (yp < g[y].size() && g[y][yp] < i)
                    ++yp;
                ans = max(ans, 1ll * num * (tong[y] - yp));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
