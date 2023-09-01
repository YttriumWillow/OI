/*
    FileName: P_7909_CSP-J_2021_分糖果.cpp
        + randomhash: a21687d83d8663a66f1b602c
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/23 星期天
    Time: 16:33:22
        + Unix Timestamp(second): 1666514002
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

longint n, L, R;

int main()
{
    cin >> n >> L >> R;
    cout << ( L / n == R / n ? R % n : n - 1 ) << endl;
    return 0;
}