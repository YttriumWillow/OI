/*
    FileName: P_1661_扩散.cpp
        + randomhash: 9a38eb80bfb83f1a71be561b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/24 星期四
    Time: 20:24:45
        + Unix Timestamp(second): 1669292685
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
const int inf = 0xfffffff;

struct Point
{
    int x, y;
    friend int operator % (Point _x, Point _y) { return abs(_x.x - _y.x) + abs(_x.y - _y.y); }
} p[51];

int n, ans = -inf;
int dis[51][51];

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            dis[i][j] = inf;
    for (reg int i = 1; i <= n - 1; ++i)
        for (reg int j = i + 1; j <= n; ++j)
            dis[i][j] = dis[j][i] = p[i] % p[j];
    for (reg int k = 1; k <= n; ++k)
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
    for (reg int i = 1; i <= n - 1; ++i)
        for (reg int j = i + 1; j <= n; ++j)
            ans = max(ans, dis[i][j]);
    printf("%d\n", (ans + 1) / 2);
    return 0;
}