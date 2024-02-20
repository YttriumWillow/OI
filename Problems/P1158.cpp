/*
    FileName: P_1158_NOIP_2010_普及组_导弹拦截.cpp
        + randomhash: 69f4e6
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/15 星期六
    Time: 15:29:31
        + Unix Timestamp(second): 1665818971
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <algorithm>
#include <climits>
#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int x_1, y_1, x_2, y_2, n, ans, v;

struct Missle
{
    int x, y;
    int dis1, dis2;
    void dis_init()
    {
        dis1 = (x - x_1) * (x - x_1) + (y - y_1) * (y - y_1);
        dis2 = (x - x_2) * (x - x_2) + (y - y_2) * (y - y_2);
    }
    friend bool operator < (Missle _x, Missle _y) { return _x.dis1 > _y.dis1; }
} m[100010];

int main()
{
    scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &m[i].x, &m[i].y);
        m[i].dis_init();
    }
    sort(m + 1, m + n + 1);
    int ans = m[1].dis1, v = -114514;
    for (reg int i = 2; i <= n; i++)
    {
        v = max(v, m[i - 1].dis2);
        ans = min(ans, m[i].dis1 + v);
    }
    printf("%d\n", ans);
    return 0;
}