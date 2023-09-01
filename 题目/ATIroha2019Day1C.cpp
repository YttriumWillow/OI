/*
    FileName: AT_iroha_2019_day_1_c_Halcyon.cpp
        + randomhash: c8aef28acd45f94c7747c48d
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/03 星期六
    Time: 16:54:13
        + Unix Timestamp(second): 1670057653
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
    for (reg int i = 0; i <= 7; ++i)
        printf("%d\n", n + i - 7);
    return 0;
}