#include <bits/stdc++.h>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}

const int MAX = 1000010;

int x, r, m, n, p, d[MAX];
double Min = -1e9, Max = 1e9;
double ans, g;
//
int main()
{
    x = read(); m = read(); n = read();
    r = m;
    while (m != -1 && n != -1)
    {
        d[m] = n;
        for (int i = p + 1; i < m; i++)
            d[i] = d[i - 1] + (n - d[p]) / (m - p);
        p = m;
        m = read(); n = read();
    }
    m = read();
    while (d[p] > m)
        p++, d[p] = d[p - 1] - m;
    for (reg int i = r; i <= p; i++)
    {
        ans = (d[x] * (x - r) - d[i] * (i - r)) * 1.0 / (d[i] - d[x]);
        g = d[i] - d[x];
        if (g > 0)
            Max = min(Max, ans);
        else
            Min = max(Min, ans);
    }
    if (Min > 0)
        printf("%d", (int)ceil(Min));
    else if (Max < 0)
        printf("%d", (int)floor(Max));
    else
        puts("0");
    return 0;
}
