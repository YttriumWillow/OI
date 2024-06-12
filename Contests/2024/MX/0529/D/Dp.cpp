#include<cstdio>
#include<iostream>
#include<queue>
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define FOR(i,s,t) for(register int i=s;i<=t;++i)
#define ll long long
#define INF 2147483647
#define BIG 200011
using namespace std;
priority_queue<pa>heap;
int n, m, k;
int x, y, z, tot, l, r, ans = 50000;
int nxt[BIG], to[BIG], las[BIG], w[BIG], dis[BIG], vis[BIG];
inline void add(int x, int y, int z) {
    nxt[++tot] = las[x];
    las[x] = tot;
    to[tot] = y;
    w[tot] = z;
    return;
}
inline int DJ(int x) {
    FOR(i, 2, n)
        dis[i] = INF, vis[i] = 0;
    vis[1] = 0;
    heap.push(mp(0, 1));
    int now, u;
    while (!heap.empty()) {
        now = heap.top().second;
        heap.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (register int e = las[now]; e; e = nxt[e]) {
            u = w[e] < x ? 0 : (w[e] - x);
            if (dis[to[e]] > dis[now] + u) {
                dis[to[e]] = dis[now] + u;
                heap.push(mp(-dis[to[e]], to[e]));
            }
        }
    }
    return dis[n] <= k ? 1 : 0;
}
inline void divide(int l, int r) {
    if (r - l <= 3) {
        FOR(i, l, r)
            if (DJ(i))
                ans = min(ans, i);
        return;
    }
    int mid = (l + r) >> 1;
    if (DJ(mid)) {
        ans = min(ans, mid);
        divide(l, mid - 1);
    }
    else
        divide(mid + 1, r);
    return;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, m) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        ans = max(z, ans);
    }
    r = ans;
    divide(l, r);
    cout << ans << endl;
    return 0;
}