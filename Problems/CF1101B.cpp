/*
    FileName: CF_1101_B_Accordion.cpp
        + randomhash: 3a40dc0f0ab5768a19ce08f9
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/16 星期天
    Time: 12:56:02
        + Unix Timestamp(second): 1665896162
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
string str;
int len, l = -1, r = -1, flag;
int main()
{
    cin >> str;
    len = str.length();

    for (reg int i = 0; i < len; ++i)
        if (str[i] == '[')
            { l = i; break; }
    if (l == -1) { puts("-1"); return 0; }
    flag = l;

    for (reg int i = l + 1; i < len; ++i)
        if (str[i] == ':')
            { l = i; break; }
    if (l == flag) { puts("-1"); return 0; }

    for (reg int i = len - 1;i >= 0;--i)
        if (str[i] == ']')
            { r = i; break; }
    if (r == -1) { puts("-1"); return 0; }
    flag = r;

    for (reg int i = r - 1;i >= 0;--i)
        if (str[i] == ':')
            { r = i; break; }
    if (r == flag) { puts("-1"); return 0; }
    if (l >= r) { puts("-1"); return 0; }
    
    int ans = 4;
    for (reg int i = l + 1;i < r;++i)
        if (str[i] == '|')
            ++ans;
    printf("%d\n", ans);
    return 0;
}

