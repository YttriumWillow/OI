/*
    FileName: T_288397_C-莲子的排版设计学.cpp
        + randomhash: 22c968c4c6e2b28f3cf69df5
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/26 星期六
    Time: 18:47:58
        + Unix Timestamp(second): 1669459678
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

string str[20010];

int n, nlen;

int main()
{
    int i = 1;
    while (getline(cin, str[i]))
    {
        i++;
    }
    n = i - 1;

    nlen = log10(n) + 1;

    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= nlen - int(log10(i) + 1); ++j)
            printf(" ");
        printf("%d ", i);
        printf("%s\n", str[i].c_str());
    }
    return 0;
}