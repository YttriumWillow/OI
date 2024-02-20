#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
inline int read()
{
    int x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int n, m, c;
int a[1000010];
struct Node
{
    longint l, r;
    longint minv, maxv;
} t[2000010];
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
void build(int now, int l, int r)
{
    t[now].l = l; t[now].r = r;
    if (l == r)
    {
        t[now].minv = t[now].maxv = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    t[now].maxv = max(t[ls(now)].maxv, t[rs(now)].maxv);
    t[now].minv = min(t[ls(now)].minv, t[rs(now)].minv);
}
int querymax(int now, int l, int r)
{
    if (l <= t[now].l && t[now].r <= r)
        return t[now].maxv;
    int mid = (t[now].l + t[now].r) >> 1;
    int ans = INT_MIN;
    if (l <= mid)
        ans = max(ans, querymax(ls(now), l, r));
    if (mid < r)
        ans = max(ans, querymax(rs(now), l, r));
    return ans;
}
int querymin(int now, int l, int r)
{
    if (l <= t[now].l && t[now].r <= r)
        return t[now].minv;
    int mid = (t[now].l + t[now].r) >> 1;
    int ans = INT_MAX;
    if (l <= mid)
        ans = min(ans, querymin(ls(now), l, r));
    if (mid < r)
        ans = min(ans, querymin(rs(now), l, r));
    return ans;
}
int main()
{
    n _read; m _read; c _read;
    for (int i = 1; i <= n; i++)
        a[i] _read;
    build(1, 1, n);
    bool found = false; int limit = n - m + 1;
    for (int i = 1; i <= limit; i++)
        if (querymax(1, i, i + m - 1) - querymin(1, i, i + m - 1) <= c)
            printf("%d\n", i), found = true;
    if (!found)
        printf("NONE\n");
    return 0;
}