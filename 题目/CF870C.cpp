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
longint n, m, q, ans;
int main()
{
    q _read;
    while (q--)
    {
        n _read; ans = 0;
        if (n <= 3 || n == 5 || n == 7 || n == 11)
        {
            printf("%d\n", -1);
            continue;
        }
        if (n & 1)
        {
            n -= 9;
            ++ans;
        }
        ans += n / 4;
        printf("%lld\n", ans);
    }
    // 5555555555555555555555555555555555
    // 5555555555555555555555555555555555
    // 5555555555555555555555555555555555
    // 5555555555555555555555555555555555
    // 5555555555555555555555555555555555
    return 0;
}