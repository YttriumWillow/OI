#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m;
longint prime[1010];
struct Node
{
    longint degree, index;
} a[1145];
vector< pair<longint, longint> > ans;
bool cmp(Node _x, Node _y)
{
    return _x.degree > _y.degree;
}
bool isprime(longint x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    scanf("%lld", &n);
    for (int i = n; i <= n * 2; i++)
        if (isprime(i))
        {
            m = i;
            break;
        }
    for (int i = 1; i <= n - 2; i++)
        a[i].degree = 2;
    for (int i = 1; i <= n; i++)
        a[i].index = i;
    int tmp = 2 * m - 2 * (n - 2);
    for (int i = 2; i * 2 <= tmp; i++)
    {
        if (isprime(i) && isprime(tmp - i))
        {
            a[n - 1].degree = tmp - i, a[n].degree = i;
            break;
        }
    }
    int pos, j;
    for (int i = 1; i <= n; i++)
    {
        sort(a + 1, a + n + 1, cmp);
        pos = 0; j = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j].index == i)
            {
                pos = j;
                break;
            }
        }
        while (a[pos].degree > 0)
        {
            j++;
            if (a[j].index == i)
                continue;
            ans.push_back(make_pair((longint)(i), a[j].index));
            a[pos].degree--;
            a[j].degree--;
        }
    }
    int len = ans.size();
    printf("%lld\n", m);
    for (int i = 0; i < len; i++)
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    return 0;
}