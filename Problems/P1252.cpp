#include <bits/stdc++.h>
using namespace std;
int a[6][11];
int ans = 0x3fffffff;
int as, bs, cs, ds, es;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 10; j++)
            cin >> a[i][j];
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 10; k++)
                for (int s = 1; s <= 10; s++)
                    for (int p = 1; p <= 10; p++)
                    {
                        if (i + j + k + s + p != 25)
                            continue;
                        if (ans > a[1][i] + a[2][j] + a[3][k] + a[4][s] + a[5][p])
                        {
                            ans = a[1][i] + a[2][j] + a[3][k] + a[4][s] + a[5][p];
                            as = i;
                            bs = j;
                            cs = k;
                            ds = s;
                            es = p;
                        }
                    }
    cout << ans << endl;
    cout << as << ' ' << bs << ' ' << cs << ' ' << ds << ' ' << es;
    return 0;
}