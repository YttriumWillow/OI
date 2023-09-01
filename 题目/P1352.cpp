#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, l, k, ans = -1145141919;
longint f[6010][2];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &f[i][1]);
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld", &l, &k);
        f[k][0] += max(f[l][0], f[l][1]);
        f[k][1] += f[l][0];
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, max(f[k][0], f[k][1]));
    printf("%lld", ans);
    return 0;
}
