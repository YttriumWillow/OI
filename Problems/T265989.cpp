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
longint n, m, a[2000010];
longint maxn = LONG_MIN, minn = LONG_MAX;
int main()
{
    n _read; m _read;
    for (int i = 1; i <= n; i++)
    {
        a[i] _read;
        maxn = max(a[i], maxn);
        minn = min(a[i], minn);
    }
    longint tmp = max(abs(minn), abs(maxn));
    // 这里列举了前两种情况，最大最小值都大于零或都小于零
    if (minn > 0)
    {
        // cout << "--1" << endl;

        if (maxn == 1 || maxn == 0) { maxn += 2; m--; }
        for (int i = 1; i <= m; i++)
            maxn <<= 1;
        cout << maxn - minn << endl;
    }
    else if (maxn < 0)
    {
        // cout << "--2" << endl;

        if (minn == -1 || minn == 0) { minn -= 2; m--; }
        for (int i = 1; i <= m; i++)
            minn *= 2;
        cout << maxn - minn << endl;
    }
    // 后面还有两种自己写：
        // 1. 最小值绝对值大于最大值
        // 2. 和1.刚好相反
    else // (minn <= 0 && maxn >= 0)
    {
        if (abs(minn) > abs(maxn))
        {
            // cout << "--3" << endl;

            if (minn == -1 || minn == 0) { minn -= 2; m--; }
            for (int i = 1; i <= m; i++)
                minn *= 2;
            cout << maxn - minn << endl;
        }
        else
        {
            // cout << "--4" << endl;

            if (maxn == 1 || maxn == 0) { maxn += 2; m--; }
            for (int i = 1; i <= m; i++)
                maxn <<= 1;
            cout << maxn - minn << endl;
        }
    }
    return 0;
}