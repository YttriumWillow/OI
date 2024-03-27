#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int tot = 0, siz[N], to[N << 1], nex[N << 1], head[N], now, n, fl = 0, tmp[N], ans = 0;
void add(int a, int b) { to[++tot] = b; nex[tot] = head[a]; head[a] = tot; }
void dfs1(int u, int fa) {
    siz[u] = 1;
    for (int i = head[u];i;i = nex[i]) {
        int v = to[i];
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}
int dfs2(int u, int fa) {
    if (fl) return 0;
    int flagg = 0;
    tmp[u] = siz[u];
    for (int i = head[u];i;i = nex[i]) {
        int v = to[i];
        if (v == fa) continue;
        int x = dfs2(v, u);
        if (fl) return 0;
        tmp[u] -= x;
        flagg += x;
        if (tmp[v] == now) flagg += now, tmp[v] = 0, tmp[u] -= now;
        else if (tmp[v] > now) fl = 1;
    }
    return flagg;
}
void solve(int x) {
    fl = 0; now = x;
    dfs2(1, 0);
    if (!fl) ans++;
}
int main() {
    // freopen("count.in", "r", stdin);
    // freopen("count.out", "w", stdout);
    int a, b;
    scanf("%d", &n);
    for (int i = 1;i <= n - 1;i++) scanf("%d%d", &a, &b), add(a, b), add(b, a);
    dfs1(1, 0);
    int xx = sqrt(n);
    for (int i = 1;i <= xx;i++)
        if (n % i == 0) {
            solve(i);
            if (n / i != i) solve(n / i);
        }
    printf("%d\n", ans);
}