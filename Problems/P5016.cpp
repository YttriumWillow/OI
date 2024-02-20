#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;
const longint inf = 1145141919810;

longint n, m, ck = inf, ans;
longint c[100010];
longint s1, s2, p1, p2;
longint l, r, lx, rx;

int main()
{
    scanf("%lld", &n);
    for (reg int i = 1; i <= n; ++i)
        scanf("%lld", &c[i]);
    scanf("%lld%lld%lld%lld", &m, &p1, &s1, &s2);
    c[p1] += s1;

    for (reg int i = 1; i <= n; ++i)
    {
        if (i < m)
            l += (m - i) * c[i];
        else
            r += (i - m) * c[i];
    }

    // printf("L:%lld R:%lld\n", l, r);

    for (reg int p2 = 1; p2 <= n; ++p2)
    {
        lx = l; rx = r;
        if (p2 < m)
            lx += (m - p2) * s2;
        else
            rx += (p2 - m) * s2;
        if (abs(lx - rx) < ck)
        {
            ans = p2;
            ck = abs(lx - rx);
        }
        // printf("at %d : %lld, %lld\n", p2, lx, rx);
    }
    printf("%lld\n", ans);
    return 0;
}
