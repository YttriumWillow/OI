#include<cstdio>
#include <iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int M = 3e5 + 10;
int n, H[M];
int lmax[M], rmin[M];
struct node
{
    int l, r, type, ck;
    node() {}
    node(int a, int b, int c, int d): l(a), r(b), type(c), ck(d) {}
    bool operator <(const node &a)const {return ck < a.ck || (ck == a.ck && type > a.type);}
} line[M << 1]; //因为每个矩形拆成两条线，所以空间开两倍
int tot;
int maxv[M << 2], lazy[M << 2];
void pushup(int o)
{
    maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
}
void pushdown(int o)
{
    if (!lazy[o]) return;
    maxv[o << 1] += lazy[o];
    maxv[o << 1 | 1] += lazy[o];
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
    lazy[o] = 0;
}
void update(int o, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R)
    {
        maxv[o] += v; lazy[o] += v;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(o);
    if (L <= mid) update(o << 1, l, mid, L, R, v);
    if (R > mid) update(o << 1 | 1, mid + 1, r, L, R, v);
    pushup(o);
}
//线段树区间加维护最大值
#define lowbit(a) ((a)&(-(a)))
ll bit[M];
void add(int a, ll b)
{
    for (; a <= n; a += lowbit(a))bit[a] += b;
}
ll query(int a)
{
    int ans = 0;
    for (; a; a -= lowbit(a))ans += bit[a];
    return ans;
}
//树状数组求逆序对个数
ll ans;//记得开long long
void init()
{
    for (int i = n; i >= 1; i--)
    {
        ans += 1ll * query(H[i]);
        add(H[i], 1);
    }   rmin[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)lmax[i] = max(lmax[i - 1], H[i]);
    for (int i = n; i >= 1; i--)rmin[i] = min(rmin[i + 1], H[i]);
    //求取前缀最大和后缀最小
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        //查询l,r，并加入扫描线
        l = lower_bound(lmax + 1, lmax + n + 1, H[i]) - lmax;
        r = lower_bound(rmin + 1, rmin + n + 1, H[i]) - rmin;
        if (rmin[r] > H[i])--r;
        if (l >= i || r <= i)continue; //排除不合法的情况
        line[++tot] = node(l, i - 1, 1, i + 1);
        line[++tot] = node(l, i - 1, -1, r + 1);
    }
    sort(line + 1, line + tot + 1); //按照y排序
}
ll maxdel;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)scanf("%d", &H[i]);
    init();
    for (int i = 1; i <= tot; i++)
    {
        update(1, 1, n, line[i].l, line[i].r, line[i].type);
        if (maxv[1] > maxdel)maxdel = maxv[1]; //更新找最大
    }
    printf("%lld\n", 1 + 2 * maxdel); //输出答案
    return 0;
}
