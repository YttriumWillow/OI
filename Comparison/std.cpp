//12252024832524
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;
const int N = 100505;
int n, q, a[N];
i64 b[N], len;
int buc[N];
int bel[N];
i64 ans[N];
struct query
{
    int l, r, id;
    bool operator < (const query &px) const
    {
        if (bel[l] != bel[px.l]) return bel[l] < bel[px.l];
        return r < px.r;
    }
} qry[N];

int Read()
{
    int x = 0, f = 1; char c = getchar();
    while (c > '9' || c < '0') {if (c == '-')f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = (x * 10) + (c ^ 48); c = getchar();}
    return x * f;
}
void Put1(i64 x)
{
    if (x > 9) Put1(x / 10);
    putchar(x % 10 ^ 48);
}
void Put(i64 x)
{
    if (x < 0) putchar('-'), x = -x;
    Put1(x);
}

int main()
{
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
    n = Read();
    q = Read();

    for (int i = 1; i <= n; ++ i)
        a[i] = Read(), b[i] = a[i];
    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;


    int blk = (int)sqrt(n);
    for (int i = 1; i <= n; ++i)
        bel[i] = (i - 1) / blk + 1;

    for (int i = 1; i <= q; ++ i)
    {
        qry[i].l = Read();
        qry[i].r = Read();
        qry[i].id = i;
    }
    sort(qry + 1, qry + q + 1);

    int l, r = 0;
    i64 cur = 0, lst = 0;
    for (int i = 1; i <= q; ++ i)
    {
        l = blk * bel[qry[i].l];//该块右端点
        if (bel[qry[i].l] > bel[qry[i - 1].l])
        {
            for (int j = 1; j <= len; ++ j)
                buc[j] = 0;
            r = l - 1;
            lst = cur = 0;
        }
        cur = lst;
        while (r < qry[i].r)
        {
            r++;
            buc[a[r]]++;
            cur = max(cur, buc[a[r]] * b[a[r]]);
        }
        while (r > qry[i].r)
        {
            buc[a[r]]--;
            r--;
        }
        lst = cur;
        while (l > qry[i].l)
        {
            l--;
            buc[a[l]]++;
            cur = max(cur, buc[a[l]] * b[a[l]]);
        }
        ans[qry[i].id] = cur;
        for (int j = blk * bel[qry[i].l] - 1; j >= l; -- j)
            buc[a[j]]--;
    }
    for (int i = 1; i <= q; ++ i)
    {
        Put(ans[i]);
        putchar('\n');
    }
    return 0;
}
