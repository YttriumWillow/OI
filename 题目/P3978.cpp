/*
    FileName: P_3978_TJOI_2015_概率论.cpp
        + randomhash: f841a675a8dcfc6812460a7b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/03 星期六
    Time: 18:46:35
        + Unix Timestamp(second): 1670064395
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

double ans;

int main()
{
    scanf("%lf", &ans);
    printf("%.16lf", (ans * ans + ans) / (4 * ans - 2));
    return 0;
}