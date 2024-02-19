#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
int n, m, ans;
int a[114514], f[114514];
int main()
{
    cin >> n >> m >> c1 >> x2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int t = lower_bound(f, f + ans + 1, a[i]) - f;
        f[t] = a[i];
        if (ans < t)
            ans = t;
    }
    cout << ans << endl;
    return 0;
}