#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint m, s, d, mx;
longint v[110][110];
longint f[500010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // dp[i][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);

    cin >> s >> d >> m;

    for (reg int i = 1; i <= s; ++i)
        for (reg int j = 1; j <= d; ++j)
            cin >> v[j][i];
    for (reg int i = 2; i <= d; ++i)
    {
        mx = 0;
        memset(f, 0, sizeof(f));
        for (reg int j = 1; j <= s; ++j)
            for (reg int k = v[i - 1][j]; k <= m; ++k)
            {
                f[k] = max(f[k], f[k - v[i - 1][j]] + v[i][j] - v[i - 1][j]);
                mx = max(mx, f[k]);
            }
        m += mx;
    }
    cout << m << endl;
    return 0;
}