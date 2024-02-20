#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define read(x) scanf("%lld", &x)
#define print(x) printf("%lld\n", x);
#define longpair pair<longint,longint>
using namespace std;
longint n, t, k, x, ans;
queue<longpair> q;
longint nation[100010];
int main()
{
    scanf("%lld", &n);
    while (n--)
    {
        scanf("%lld%lld", &t, &k);
        while (!q.empty())
        {
            longpair x = q.front();
            if (x.second + 86400 <= t)
            {
                nation[x.first]--;
                if (nation[x.first] == 0)
                    ans--;
                q.pop();
                continue;
            }
            break;
        }
        while (k--)
        {
            scanf("%lld", &x);
            q.push(make_pair(x, t));
            nation[x]++;
            if (nation[x] == 1)
                ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}