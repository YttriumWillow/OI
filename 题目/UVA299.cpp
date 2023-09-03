#include <bits/stdc++.h>
#define reg register
using namespace std;
int n, a[5000001], b[5000001], T;
long long ans;
inline void msort(int l, int r)
{
    int mid = (l + r) >> 1;
    if (l == r) return;
    else
    {
        msort(l, mid);
        msort(mid + 1, r);
    }
    reg int i = l;
    reg int j = mid + 1;
    reg int t = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            ans += mid - i + 1;
            b[t++] = a[j];
            ++j;
        }
        else
        {
            b[t++] = a[i];
            ++i;
        }
    }
    while (i <= mid)
    {
        b[t++] = a[i];
        ++i;
    }
    while (j <= r)
    {
        b[t++] = a[j];
        ++j;
    }
    for (reg int i = l; i <= r; ++i)
    {
        a[i] = b[i];
    }
    return;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = 0;
        for (reg int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), b[i] = 0;
        msort(1, n);
        printf("Optimal train swapping takes %lld swaps.\n", ans);
    }
    return 0;
}
