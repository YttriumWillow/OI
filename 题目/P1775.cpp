#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint n;
longint sum[310], a[310];
longint f[310][310];
int main()
{
    scanf("%lld", &n);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
        }
    cout << f[1][n] << endl;
    return 0;
}