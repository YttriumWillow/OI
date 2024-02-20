/*
    FileName: P_1095_NOIP_2007_普及组_守望者的逃离.cpp
        + randomhash: 6add654f1e92e00e29c3191d
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/17 星期一
    Time: 20:20:35
        + Unix Timestamp(second): 1666009235
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

int m, s, t, dis1, dis2;

int main()
{
    scanf("%d%d%d", &m, &s, &t);
    for (reg int i = 1; i <= t; i++)
    {
        dis1 += 17;
        if (m >= 10)
            dis2 += 60, m -= 10;
        else
            m += 4;
        dis1 = max(dis1, dis2);
        if (dis1 > s)
        {
            printf("Yes\n%d\n", i);
            return 0;
        }
    }
    printf("No\n%d\n", dis1);
    return 0;
}