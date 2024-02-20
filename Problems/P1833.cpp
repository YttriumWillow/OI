#include <bits/stdc++.h>
#define longint long long
#define reg register
#define qwq puts("fzy qwq");
using namespace std;
longint n, ans, top;
longint h1, m1, h2, m2;
longint t[10010], c[10010], p[10010], co[1000010], v[1000010];
longint f[1145];
int main()
{
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    int ti = (h2 * 60 + m2) - (h1 * 60 + m1);
    scanf("%d", &n);
    for (reg int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &t[i], &c[i], &p[i]);
        if (p[i] == 0) p[i] = 999999;
    }
    for (reg int i = 1; i <= n; i++)
    {
        int x = 1;
        while (p[i])
        {
            co[++top] = x * t[i];
            v[top] = x * c[i];
            p[i] -= x;
            x *= 2;
            if (p[i] < x)
            {
                co[++top] = t[i] * p[i];
                v[top] = c[i] * p[i];
                break;
            }
        }
    }
    for (reg int i = 1; i <= top; i++)
        for (reg int j = ti; j >= co[i]; j--)
            f[j] = max(f[j], f[j - co[i]] + v[i]);
    printf("%d\n", f[ti]);
    return 0;
}