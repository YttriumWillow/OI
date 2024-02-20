#include <bits/stdc++.h>
#define longint long long
#define reg register
#define qwq puts("fzy qwq");
using namespace std;
longint n, a[114514], ans;
int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    while (n > 3)
    {
        ans += min(a[1] * 2 + a[n] + a[n - 1],
            a[1] + a[2] * 2 + a[n]);
        n -= 2;
    }
    if (n == 2)
        ans += a[2];
    if (n == 3)
        ans += a[1] + a[2] + a[3];
    printf("%d\n", ans);
    return 0;
}