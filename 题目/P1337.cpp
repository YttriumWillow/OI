/*
    FileName: P_1337_JSOI_2004_平衡点_吊打XXX.cpp
        + randomhash: f2a27f7884165195071058ae
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/14 星期三
    Time: 20:21:19
        + Unix Timestamp(second): 1671020479
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>
#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

struct Point
{
    double x = 0, y = 0, f = 0;
    Point() {}
    Point(double _x, double _y, double _f):
        x(_x), y(_y), f(_f)
    {
    }
    friend double operator % (Point a, Point b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
} p[1010];


int n;
Point ans;
double step = 10000.0;

int main()
{
    auto modify = [](double& now)
    {
        double g, xx = 0, yy = 0;
        for (reg int i = 1; i <= n; ++i)
        {
            g = ans % p[i];
            if (g != 0) // 后面不能除以 0 欸
            {
                xx += p[i].f / g * (p[i].x - ans.x);
                yy += p[i].f / g * (p[i].y - ans.y);
            }
        }
        g = sqrt(xx * xx + yy * yy);
        ans.x += now / g * xx;
        ans.y += now / g * yy;

        now *= 0.621;
    };

    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].f);
    while (step > 1e-4)
        modify(step);
    printf("%.3lf %.3lf\n", ans.x, ans.y);
    return 0;
}