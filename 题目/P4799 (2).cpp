#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, m, ans;
longint price[41];
longint f[100000010];

inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}

int main()
{
    n = read(); m = read(); f[0] = 1;
    for (reg int i = 1; i <= n; ++i)
        price[i] = read();
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = m; j >= price[i]; --j)
            f[j] += f[j - price[i]];
    for (reg int i = 0; i <= m; ++i)
        ans += f[i];
    printf("%lld\n", ans);
    return 0;
}