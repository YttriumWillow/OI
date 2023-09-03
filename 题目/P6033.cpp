#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') { sgn = -1; } ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
longint n, m, ans;
longint a[10000010];
longint b[100010];
queue<longint> q1, q2;
inline longint get()
{
    if (q2.empty() || (!q1.empty() && q1.front() < q2.front()))
    {
        longint t = q1.front();
        q1.pop();
        return t;
    }
    else
    {
        longint t = q2.front();
        q2.pop();
        return t;
    }
}
int main()
{
    n _read;
    for (reg longint i = 1; i <= n; i++)
        b[a[i] _read]++;
    for (reg longint i = 1; i <= 100000; i++)
        for (reg longint j = 1; j <= b[i]; j++)
            q1.push(i);
    for (reg longint i = 1; i < n; i++)
    {
        longint x = get();
        longint y = get();
        ans += x + y; q2.push(x + y);
    }
    cout << ans << endl;
    return 0;
}