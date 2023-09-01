/*
    FileName: P_1469_找筷子.cpp
        + randomhash: 8ba9cf0bea0399ffeff38207
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/28 星期五
    Time: 15:18:56
        + Unix Timestamp(second): 1666941536
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

int n, l, ans;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &l);
        ans = ans ^ l;
    }
    printf("%d\n", ans);
    return 0;
}