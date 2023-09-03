#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
const longint mod = 1000000007;
longint k, ans, tmp, flag;
longint f[110], limit, x, y;
int main()
{

    // x = k * -1 ^ i       * f[i - 1];
    // y = k * -1 ^ (i + 1) * f[i - 2];

    cin >> k;
    f[1] = f[2] = 1;
    ans = k - 1;
    for (int i = 3; i <= 100; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= k)
        {
            limit = i;
            break;
        }
    }
    for (int i = 5; i <= limit + 2; i++)
    {
        flag = pow(-1, i);
        x = k * flag * f[i - 1];
        y = k * flag * f[i - 2] * -1;
        if (x < 0)
        {
            y -= (abs(x) / f[i - 1] + 1) * f[i - 2];
            if (y > 0)
                ans = ans + ceil(1.0 * y / f[i - 2]);
            ans %= mod;
        }
        else if (y < 0)
        {
            x -= (abs(y) / f[i - 2] + 1) * f[i - 1];
            if (x > 0)
                ans = ans + ceil(1.0 * x / f[i - 1]);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}