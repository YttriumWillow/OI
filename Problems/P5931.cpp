/*
    FileName: P_5931_清华集训_2015_灯泡.cpp
        + randomhash: 269dd8da59e8d41d1c58ff41
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/25 星期五
    Time: 20:32:41
        + Unix Timestamp(second): 1669379561
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

int T, cnt;
double H, h, D;

int main()
{
    scanf("%d", &T);

    auto f = [](double x) -> double
    {
        if (x <= h * D / H)
            return x + (H - (H - h) * D / (D - x));
        else
            return x - D + ((D - x) * H / (H - h));
    };

    while (T--)
    {
        scanf("%lf%lf%lf", &H, &h, &D);
        double l = 0, r = 1e8;
        // cnt = 1e4;
        while (r - l >= 1e-7)
        {
            double lmid = l + (r - l) / 3;
            double rmid = r - (r - l) / 3;
            if (f(lmid) > f(rmid))
                r = rmid;
            else
                l = lmid;
        }
        printf("%.3lf\n", (f(l) + f(r)) / 2 + 1e-7);
    }
    return 0;
}
