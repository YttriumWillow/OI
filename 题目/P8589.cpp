/*
    FileName: P_8589_JROI-_8_对了_还有花_少女_银河.cpp
        + randomhash: 60967db068ec1752994e8809
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/23 星期天
    Time: 15:41:48
        + Unix Timestamp(second): 1666510908
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

int n;

int main()
{
    scanf("%d", &n);
    n -= 1;
    if (n % 4 != 0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("0");
        while (n)
        {
            printf("1100");
            n -= 4;
        }
    }
    return 0;
}