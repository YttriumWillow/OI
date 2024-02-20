#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint n, minans = 1145141919810, maxans;
longint sum[310], a[310];
longint f1[310][310];
longint f2[310][310];
int main()
{
    scanf("%lld", &n);
    memset(f1, 0x3f, sizeof(f1));
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= 2 * n; i++)
    {
        a[i + n] = a[i];
        sum[i] = sum[i - 1] + a[i];
        f1[i][i] = f2[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++) //  && k <= 2 * n
            {
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k + 1][j] + sum[j] - sum[i - 1]);
                f2[i][j] = max(f2[i][j], f2[i][k] + f2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    for (int i = 1; i <= n; i++)
    {
        minans = min(minans, f1[i][i + n - 1]);
        maxans = max(maxans, f2[i][i + n - 1]);
    }
    printf("%lld\n", minans);
    printf("%lld\n", maxans);;
    return 0;
}