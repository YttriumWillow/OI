#include <bits/stdc++.h>
using namespace std;
#define ROF(i, a, b) for (int i = a; i >= b; i--)
const int maxn = 250000;
int n, t, m, u, v;
int tot = 0, pre[maxn], son[maxn], now[maxn];
int dfn[maxn], siz[maxn];
int f[maxn][18], mx[maxn], dep[maxn];
int up[maxn][18], Ans = 0;
int sum[maxn];
vector<int> S[maxn];
namespace sgt {
int rt[maxn], sum[maxn << 5], ls[maxn << 5], rs[maxn << 5], cnt = 0;
void update(int p) { sum[p] = sum[ls[p]] + sum[rs[p]]; }
void change(int &p, int l, int r, int x) {
    ls[++cnt] = ls[p], rs[cnt] = rs[p], sum[cnt] = sum[p];
    p = cnt;
    if (l == r)
        return sum[p]++, void();
    int mid = (l + r) / 2;
    if (x <= mid)
        change(ls[p], l, mid, x);
    else
        change(rs[p], mid + 1, r, x);
    update(p);
}
int query(int p, int q, int l, int r, int x, int y) {
    if (l >= x && r <= y)
        return sum[p] - sum[q];
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
        ans += query(ls[p], ls[q], l, mid, x, y);
    if (y > mid)
        ans += query(rs[p], rs[q], mid + 1, r, x, y);
    return ans;
}
};  // namespace sgt
void put(int x, int y) {
    pre[++tot] = now[x];
    now[x] = tot;
    son[tot] = y;
}
int LCA(int u, int v) {
    if (u == v)
        return u;
    if (dep[u] < dep[v])
        swap(u, v);
    ROF(i, 17, 0) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    if (u == v)
        return u;
    ROF(i, 17, 0) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return f[u][0];
}
int upjump(int x, int u) {
    for (int i = 17; i >= 0; i--)
        if (dep[up[x][i]] > dep[u])
            x = up[x][i], Ans += (1 << i);
    return x;
}
void update(int x, int y) {
    if (dep[mx[x]] > dep[y])
        mx[x] = y;
}
void dfs1(int x, int fa) {
    dfn[x] = ++dfn[0], siz[x] = 1;
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 1; i <= 17; i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for (int p = now[x]; p; p = pre[p]) {
        int t = son[p];
        if (t == fa)
            continue;
        dfs1(t, x);
        siz[x] += siz[t];
    }
}
void dfs2(int x, int fa) {
    for (int p = now[x]; p; p = pre[p]) {
        int t = son[p];
        if (t == fa)
            continue;
        dfs2(t, x);
        update(x, mx[t]);
    }
}
void dfs3(int x, int fa) {
    up[x][0] = mx[x];
    for (int i = 1; i <= 17; i++) up[x][i] = up[up[x][i - 1]][i - 1];
    for (int p = now[x]; p; p = pre[p]) {
        int t = son[p];
        if (t == fa)
            continue;
        dfs3(t, x);
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &t, &m);
    for (int i = 1; i < n; i++) scanf("%d%d", &u, &v), put(u, v), put(v, u);
    for (int j = 1; j <= n; j++) mx[j] = j;
    dfs1(1, 0);
    for (int i = 1, x, y; i <= t; i++) {
        scanf("%d%d", &x, &y), S[dfn[x]].push_back(dfn[y]), S[dfn[y]].push_back(dfn[x]);
        int p = LCA(x, y);
        if (p != x)
            update(x, p);
        if (p != y)
            update(y, p);
    }
    for (int i = 1; i <= n; i++) {
        sgt::rt[i] = sgt::rt[i - 1];
        for (auto t : S[i]) sgt::change(sgt::rt[i], 1, n, t);
    }
    dfs2(1, 0);
    dfs3(1, 0);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        int Lca = LCA(u, v);
        Ans = 0;
        int t1 = upjump(u, Lca), t2 = upjump(v, Lca);
        if (t1 != Lca)
            Ans++;
        if (t2 != Lca)
            Ans++;
        if (dep[up[t1][0]] > dep[Lca] || dep[up[t2][0]] > dep[Lca])
            Ans = -1;
        else if (Lca != t1 && Lca != t2 &&
                 sgt::query(sgt::rt[dfn[t1] + siz[t1] - 1], sgt::rt[dfn[t1] - 1], 1, n, dfn[t2],
                            dfn[t2] + siz[t2] - 1))
            Ans--;
        if (Ans == -1)
            puts("-1");
        else
            printf("%d\n", Ans - 1);
    }

    return 0;
}