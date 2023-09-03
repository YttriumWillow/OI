/*
    FileName: P_5076_深基_16_例_7_普通二叉树_简化版.cpp
        + randomhash: 53688c6402780f830d5cc389
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/17 星期一
    Time: 19:53:44
        + Unix Timestamp(second): 1666007624
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <set>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

multiset<int> s = { 0x7fffffff, -0x7fffffff };

int main()
{
    reg int Q, opr, x;
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d%d", &opr, &x);
        if (opr == 1)
        {
            auto p = s.lower_bound(x); int ord = 0;
            for (auto i = s.begin(); i != p; i++, ord++) {}
            printf("%d\n", ord);
        }
        if (opr == 2)
        {
            int ord = -1;
            for (auto i : s) if (++ord == x) printf("%d\n", i);
        }
        if (opr == 3)
            printf("%d\n", *(--s.lower_bound(x)));
        if (opr == 4)
            printf("%d\n", *s.upper_bound(x));
        if (opr == 5)
            s.insert(x);
    }
    return 0;
}