#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, h, r, T;
longint f[1010];
longint upside, downside;
longint ups[1010], dws[1010];

struct Hole
{
    longint x, y, z;
    friend bool operator & (Hole _x, Hole _y) { return ((_x.x - _y.x) * (_x.x - _y.x) + (_x.y - _y.y) * (_x.y - _y.y) + (_x.z - _y.z) * (_x.z - _y.z)) <= 4 * r * r; }
} hole[1010];

longint find(longint x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &h, &r);
        for (int i = 1; i <= n; i++)
            f[i] = i;
        upside = downside = 0;

        for (reg int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &hole[i].x, &hole[i].y, &hole[i].z);

            if (hole[i].z + r >= h)
                ups[++upside] = i;
            if (hole[i].z - r <= 0)
                dws[++downside] = i;

            for (reg int j = 1; j <= i; j++)
            {
                // 防爆蛋
                // if ((hole[i].x - hole[j].x) * (hole[i].x - hole[j].x) + (hole[i].y - hole[j].y) * (hole[i].y - hole[j].y) > 4 * r * r) continue;
                if (hole[i] & hole[j])
                {
                    longint x = find(i);
                    longint y = find(j);
                    if (x != y) f[x] = y;
                }
            }
        }
        int ans = 0;
        for (reg int i = 1; i <= upside; i++)
        {
            for (reg int j = 1; j <= downside; j++)
                if (find(ups[i]) == find(dws[j]))
                {
                    ans = 1;
                    break;
                }
            if (ans == 1)
                break;
        }
        if (ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}