#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
longint cnt, n, q, num[10000010], x, awa, ans;
longint dfs(longint* num, longint x, longint l, longint r)
{
    if (l == r)
    {
        ans = min(cnt, ans);
        return l;
    }
    cnt++;
    longint tmp = cnt;
    longint res = -1;

    longint w = 0;
    longint mid = (l + r + w) / 2;
    if (num[mid] - w < x) res = dfs(num, x, mid + !w, r);
    else res = dfs(num, x, l, mid - w);
    
    cnt = tmp;

    w = 1;
    mid = (l + r + w) / 2;
    if (num[mid] - w < x) res = dfs(num, x, mid + !w, r);
    else res = dfs(num, x, l, mid - w);
    return res;
}
longint find2(longint* num, longint x, longint len)
{
    ans = LONG_MAX;
    cnt = 0;
    return dfs(num, x, 1, len);
}
int main()
{
    // srand(time(0));// 这是一个拼人品的代码qwq
    n _read;
    for (int i = 1; i <= n; i++)
        num[i] _read;
    q _read;
    while (q--)
    {
        x _read;
        awa = find2(num, x, n);
        cout << ans << endl;
    }
    return 0;
}