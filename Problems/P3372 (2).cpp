#include <bits/stdc++.h>
#define qwq puts("fzy_qwq");
#define longint long long
#define reg register
#define _read =read()
#define ls(k) (k)<<1
#define rs(k) (k)<<1|1
using namespace std;
struct fzy_Node
{
    longint l, r;
    longint val, tag;// tag -> lazy_tag
} tree[1000010];
longint n, m, opr, x, y, k;
longint a[500010];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
// 建树
void build(longint p, longint l, longint r)
{
    tree[p].l = l;
    tree[p].r = r;
    if (l == r)
    {
        tree[p].val = a[l];
        // qwq; 
        return;
    }
    longint mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tree[p].val = tree[ls(p)].val + tree[rs(p)].val;
}
// 传标记
void spread(longint p)
{
    if (tree[p].tag)
    {
        tree[ls(p)].val += tree[p].tag * (tree[ls(p)].r - tree[ls(p)].l + 1);
        tree[rs(p)].val += tree[p].tag * (tree[rs(p)].r - tree[rs(p)].l + 1);
        tree[ls(p)].tag += tree[p].tag;
        tree[rs(p)].tag += tree[p].tag;
        tree[p].tag = 0;
    }
}
//区间修改(增加)
void change(longint p, longint x, longint y, longint z)
{
    if (x <= tree[p].l && tree[p].r <= y)
    {
        tree[p].val += z * (tree[p].r - tree[p].l + 1);
        tree[p].tag += z;
        return;
    }
    spread(p);
    longint mid = (tree[p].l + tree[p].r) >> 1;
    if (x <= mid)
        change(ls(p), x, y, z);
    if (y >= mid + 1)
        change(rs(p), x, y, z);
    tree[p].val = tree[ls(p)].val + tree[rs(p)].val;
}
longint ask(longint p, longint x, longint y)
{
    if (x <= tree[p].l && tree[p].r <= y)
        return tree[p].val;
    spread(p);
    longint mid = (tree[p].l + tree[p].r) >> 1;
    longint ans = 0;
    if (x <= mid)
        ans += ask(ls(p), x, y);
    if (y >= mid + 1)
        ans += ask(rs(p), x, y);
    return ans;
}
int main()
{
    n _read; m _read;
    for (int i = 1; i <= n; i++)
        a[i] _read;
    build(1, 1, n);
    while (m--)
    {
        opr _read;
        switch (opr)
        {
        case 1:
            x _read; y _read; k _read;
            change(1, x, y, k);
            break;
        case 2:
            x _read; y _read;
            printf("%lld\n", ask(1, x, y));
            break;
        }
    }
    return 0;
}