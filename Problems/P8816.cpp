/*
    FileName: P_8816_CSP-J_2022_上升点列.cpp
        + randomhash: 24d2a65eab787e41daa6132e
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/27 星期天
    Time: 13:29:41
        + Unix Timestamp(second): 1669526981
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>
#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

struct Point
{
    int x, y;
    friend bool operator < (Point _a, Point _b) { return (_a.x != _b.x) ? _a.x < _b.x : _a.y < _b.y; }
} p[510];

int n, k, d, ans;
int f[510][110];

int main()
{
    scanf("%d%d", &n, &k);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1);

    for (reg int i = 1; i <= n; ++i)
    {
        f[i][k] = 1;
        for (reg int j = 0; j <= k; ++j)
        {
            for (reg int kk = 1; kk < i; ++kk)
            {
                if (p[kk].x > p[i].x || p[kk].y > p[i].y)
                    continue;
                d = abs(p[i].x - p[kk].x) + abs(p[i].y - p[kk].y) - 1;
                if (j + d > k)
                    continue;
                f[i][j] = max(f[i][j], f[kk][j + d] + d + 1);
            }
        }
    }

    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 0; j <= k; ++j)
            ans = max(ans, j + f[i][j]);
    
    printf("%d\n", ans);
    return 0;
}