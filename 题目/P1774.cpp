#include<bits/stdc++.h>
using namespace std;
long long n, m, ans, b[500010], f[500010];
struct node
{
    long long val, id;
} a[500010];
bool cmp(node x, node y)
{
    return x.val > y.val;
}
long long lowbit(long long x)
{
    return x & -x;
}
void step1(long long pos, long long k)
{
    for (int i = pos;i <= m;i += lowbit(i))
        f[i] += k;
}
long long step2(long long pos)
{
    long long ret = 0;
    for (int i = pos;i > 0;i -= lowbit(i))
        ret += f[i];
    return ret;
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    m = 1;
    b[a[1].id] = m;
    for (int i = 2;i <= n;i++)
        if (a[i].val == a[i - 1].val)
            b[a[i].id] = m;
        else
        {
            m++;
            b[a[i].id] = m;
        }
    for (int i = 1;i <= n;i++)
    {
        ans += step2(b[i] - 1);
        step1(b[i], 1);
    }
    printf("%lld", ans);
    return 0;
}