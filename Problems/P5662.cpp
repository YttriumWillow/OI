#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint T, n, m, now;
longint v[110][110];
longint f[10010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // dp[i][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);

    cin >> T >> n >> m;

    for (reg int i = 1; i <= T; ++i)
        for (reg int j = 1; j <= n; ++j)
            cin >> v[i][j];
    for (reg int i = 2; i <= T; ++i)
    {
        memset(f, 0, sizeof(f));
        for (reg int j = 1; j <= n; ++j)
            for (reg int k = v[i - 1][j]; k <= m; ++k)
                f[k] = max(f[k], f[k - v[i - 1][j]] + v[i][j] - v[i - 1][j]);
        m += f[m];
    }
    cout << m << endl;
    return 0;
}