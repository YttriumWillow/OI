#include <bits/stdc++.h>
using namespace std;
inline int read() {
    char c = getchar();
    int x = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
struct edge {
    int to, nxt;
} e[200005], pa[200005], a[200005];
struct query {
    int x, yl, yr, id, k;
} b[200005];
#define MN 100005
int n, cnt, cnt2, h[MN], hp[MN], ho[MN], dep[MN], dfn[MN], ed[MN], fa[MN][20], bz[MN][20], ans[MN], rq[MN],
    tree[MN];
inline void adde(int x, int y) {
    e[++cnt] = (edge){ y, h[x] };
    h[x] = cnt;
}
inline void addp(int x, int y) {
    //	cout<<"addP: "<<x<<' '<<y<<endl;
    pa[++cnt] = (edge){ y, hp[x] };
    hp[x] = cnt;
}
inline void addo(int x, int y) {
    a[++cnt2] = (edge){ y, ho[x] };
    ho[x] = cnt2;
}
void dfs(int x, int f) {
    dfn[x] = ++cnt;
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i < 19; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = h[x]; i; i = e[i].nxt)
        if (e[i].to != f)
            dfs(e[i].to, x);
    ed[x] = cnt;
}
int dfs2(int x) {
    int mx = x;
    for (int i = h[x]; i; i = e[i].nxt)
        if (e[i].to != fa[x][0]) {
            int t = dfs2(e[i].to);
            if (dep[t] < dep[mx])
                mx = t;
        }
    for (int i = hp[x]; i; i = pa[i].nxt) {
        int t = pa[i].to;
        if (dep[t] < dep[mx])
            mx = t;
    }
    //	cout<<"bz: "<<x<<' '<<mx<<endl;
    return bz[x][0] = mx;
}
inline int LCA(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    int d = dep[x] - dep[y], i;
    for (i = 0; i < 19; i++)
        if ((d >> i) & 1)
            x = fa[x][i];
    if (x == y)
        return x;
    for (i = 18; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
inline bool cmp(query x, query y) { return x.x < y.x; }
inline void add(int x) {
    for (; x <= n; x += x & (-x)) tree[x]++;
}
inline int ask(int x) {
    int res = 0;
    for (; x; x &= x - 1) res += tree[x];
    return res;
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    n = read();
    int m = read(), q = read(), i, j, x, y, l;
    for (i = 1; i < n; i++) {
        x = read(), y = read();
        adde(x, y), adde(y, x);
    }
    cnt = 0;
    dfs(1, 0);
    cnt = 0;
    while (m--) {
        x = read(), y = read();
        addo(dfn[x], dfn[y]), addo(dfn[y], dfn[x]);
        l = LCA(x, y);
        addp(x, l), addp(y, l);
    }
    dfs2(1);
    for (l = 1; l < 19; l++)
        for (i = 1; i <= n; i++) bz[i][l] = bz[bz[i][l - 1]][l - 1];
    cnt = 0;
    for (int t = 1; t <= q; t++) {
        x = read(), y = read();
        l = LCA(x, y);
        if (l == x)
            swap(x, y);
        if (l == y) {
            y = dep[y];
            int res = 0;
            for (i = 18; ~i; i--)
                if (dep[bz[x][i]] > y) {
                    x = bz[x][i];
                    res += (1 << i);
                }
            if (dep[bz[x][0]] > y)
                ans[t] = -1;
            else
                ans[t] = res;
            continue;
        }
        l = dep[l];
        int res = 0;
        for (i = 18; ~i; i--)
            if (dep[bz[x][i]] > l) {
                x = bz[x][i];
                res += (1 << i);
            }
        for (i = 18; ~i; i--)
            if (dep[bz[y][i]] > l) {
                y = bz[y][i];
                res += (1 << i);
            }
        if (dep[bz[x][0]] > l || dep[bz[y][0]] > l)
            ans[t] = -1;
        else {
            ans[t] = res + 1;
            b[++cnt] = (query){ dfn[x] - 1, dfn[y], ed[y], t, -1 };
            b[++cnt] = (query){ ed[x], dfn[y], ed[y], t, 1 };
        }
    }
    sort(b + 1, b + cnt + 1, cmp);
    for (i = j = 1; i <= n; i++) {
        for (x = ho[i]; x; x = a[x].nxt) add(a[x].to);
        while (j <= cnt && b[j].x == i) {
            rq[b[j].id] += b[j].k * (ask(b[j].yr) - ask(b[j].yl - 1));
            j++;
        }
    }
    for (i = 1; i <= q; i++) {
        //		cout<<"rq: "<<i<<' '<<rq[i]<<endl;
        if (ans[i] == -1)
            putchar('-'), putchar('1');
        else if (rq[i])
            write(ans[i] - 1);
        else
            write(ans[i]);
        putchar('\n');
    }
    return 0;
}