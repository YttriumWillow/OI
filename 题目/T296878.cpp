/*
    FileName: T_296878_UOI-R_1_磁铁.cpp
        + randomhash: 6eb39d76780cbd15a360accb
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/10 星期六
    Time: 17:12:27
        + Unix Timestamp(second): 1670663547
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int t;
string a, b;

bool check(string& a, string& b)
{
    int len = a.size(), now = 0;
    for (reg int i = 0; i < len; ++i)
    {
        if (a[i] == b[now])
        {
            now++;
        }
    }
    return now == int(b.size());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a.size() > b.size())
            cout << (check(a, b) ? 'Y' : 'N') << endl;
        else
            cout << (check(b, a) ? 'Y' : 'N') << endl;
    }
    return 0;
}