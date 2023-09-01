/*
    FileName: AT_joi_2016_yo_a_科目選択_Selecting_Subjects.cpp
        + randomhash: 341b8b037ce7d05cbbec8c37
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/03 星期六
    Time: 18:35:20
        + Unix Timestamp(second): 1670063720
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

int a, b, c, d, e, f;

int main()
{
    scanf("%d%d%d%d%d%d", &a, &b ,&c, &d, &e, &f);
    printf("%d\n", (a + b + c + d) - min(min(a, b), min(c, d)) + max(e, f));
    return 0;
}