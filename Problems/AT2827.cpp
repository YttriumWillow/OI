#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
int n, m, ans;
int a[114514], f[114514];
int main()
{
    cin >> n;
    for (reg int i = 1; i <= n; i++)
        cin >> a[i];
    for (reg int i = 1; i <= n; i++)
    {
        int t = lower_bound(f, f + ans + 1, a[i]) - f;
        f[t] = a[i];
        if (ans < t)
            ans = t;
    }
    cout << ans << endl;
    return 0;
}