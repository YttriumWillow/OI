/*
    FileName: AT_iroha_2019_day_1_b_ローリング_老人と海.cpp
        + randomhash: e89bc84bc5c4daba09eef9e8
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/03 星期六
    Time: 17:37:18
        + Unix Timestamp(second): 1670060238
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

string s;
int k, len;

void opr()
{
    s.push_back(s[0]);
    s.erase(0, 1);
}

int main()
{
    cin >> s >> k;
    for (reg int i = 1; i <= k; ++i)
        opr();
    cout << s << endl;
    return 0;
}