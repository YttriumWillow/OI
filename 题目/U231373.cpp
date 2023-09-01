#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~")
#define longint long long
using namespace std;
longint n, x, p, q, ans;
longint t[114514];
double r, sleep, today;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> x >> p >> q;
    r = p * 1.0 / q;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    longint ans = 1, i = 1;
    while (i < n)
    {
        while (r * x * ans > sleep + (x - t[i])) // 该天干活 + 睡觉
        {
            ans++;
            sleep += x;
        }
        today = 0;
        while (r * x * ans < sleep + (x - today))
        {
            today += t[i];
            i++;
        }
        sleep += today;
        ans++;
    }
    cout << ans << endl;
    return 0;
}