/*
    FileName: P_8585_球状精灵的传说.cpp
        + randomhash: 2afed320daa687d26491ee5a
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/16 星期天
    Time: 16:01:25
        + Unix Timestamp(second): 1665907285
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

struct Fair
{
    int xx, yy, zz;
    int x, y, z, id;
    Fair() {}
    Fair(int qaq) : x(0), y(0), z(qaq) {}
    inline void input(int now)
    {
        scanf("%d %d %d", &x, &y, &z); id = now;
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
    }
    inline int val(const Fair& b)
    {
        xx = x + b.x; yy = y; zz = z;
        int m = min(xx, min(yy, zz));
        return m * m * m / 4;
    }
} mid, a[500010];

int n, ans = -1, flag, single, l, r;
int f[1010][1010], id[1010][1010];

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
    {
        a[i].input(i);
        if (a[i].val(mid) > ans)
        {
            flag = 1; single = i;
            ans = a[i].val(mid);
        }
        if (a[i].val(a[id[a[i].y][a[i].z]]) > ans)
        {
            flag = 2; l = id[a[i].y][a[i].z]; r = i;
            ans = a[i].val(a[id[a[i].y][a[i].z]]);
        }
        if (a[i].x > f[a[i].y][a[i].z])
        {
            id[a[i].y][a[i].z] = a[i].id;
            f[a[i].y][a[i].z] = a[i].x;
        }
    }
    if (flag == 1) printf("0\n%d\n%d", single, a[single].val(mid));
    else printf("1\n%d %d\n%d", l, r, a[l].val(a[r]));
    return 0;
}
