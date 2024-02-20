#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint n, m, x, y;
longint f[2500], ans;
char ch;
longint find(longint x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void init()
{
    for (int i = 1; i <= 2 * n; i++)
        f[i] = i;
}
int main()
{
    cin >> n >> m;
    init();
    while (m--)
    {
        cin >> ch >> x >> y;
        if (ch == 'F')
            f[find(x)] = find(y);
        else
        {
            f[find(x + n)] = find(y);
            f[find(y + n)] = find(x);
        }
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == i)
            ans++;
    cout << ans << endl;
    return 0;
}