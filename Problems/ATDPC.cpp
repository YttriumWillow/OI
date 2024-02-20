/*
    FileName: AT_dp_c_Vacation.cpp
        + randomhash: 6cf1524700914b44c1082fbf
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/22 星期六
    Time: 17:00:01
        + Unix Timestamp(second): 1666429201
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
int act[100010][4];
int f[100010][4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (reg int i = 1; i <= n; ++i)
        cin >> act[i][1] >> act[i][2] >> act[i][3];
    for (reg int i = 1; i <= n; i++)
    {
        f[i][1] = max(f[i - 1][2], f[i - 1][3]) + act[i][1];
        f[i][2] = max(f[i - 1][1], f[i - 1][3]) + act[i][2];
        f[i][3] = max(f[i - 1][1], f[i - 1][2]) + act[i][3];
    }
    cout << max(f[n][1], max(f[n][2], f[n][3])) << endl;
    return 0;
}