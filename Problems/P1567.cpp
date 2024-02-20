#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, a[10000010], ans, tmp = 1;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read;
    for (int i = 1; i <= n; i++)
        a[i] _read;
    for (int i = 2; i <= n; i++)
        if (a[i - 1] < a[i])
            tmp++;
        else
        {
            // printf("a[%d](%d)>=a[%d](%d)\n", i - 1, a[i - 1], i, a[i]);
            ans = max(ans, tmp);
            tmp = 1;
        }
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}