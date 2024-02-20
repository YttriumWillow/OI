#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, ans, stone[500010], tmp;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
inline void print(longint i, longint j)
{
    printf("%d %d\n", j, i);
    for (reg int x = 1; x <= n; x++)
        printf("%d ", stone[x]);
    printf("\n");
}
int main()
{
    n _read;
    ans = 0;
    for (reg int i = 1; i <= n; i++)
    {
        stone[i] _read;
        ans ^= stone[i];
    }
    if (!ans)
        printf("lose\n");
    else
    {
        for (reg int i = 1; i <= n; i++)
            for (reg int j = 1; j <= stone[i]; j++)
            {
                tmp = stone[i];
                stone[i] = stone[i] - j;
                ans = 0;
                for (reg int k = 1; k <= n; k++)
                    ans ^= stone[k];
                if (!ans)
                {
                    print(i, j);
                    return 0;
                }
                stone[i] = tmp;
            }
    }
    return 0;
}