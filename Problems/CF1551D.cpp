/*
    FileName: CF_1551_D_1_Domino_easy_version.cpp
        + randomhash: 39bcc5
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/15 星期六
    Time: 11:08:31
        + Unix Timestamp(second): 1665803311
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

int n, m, T, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        if (n % 2 == 0 && m % 2 == 0)
            cout << ((k % 2 == 0) ? "YES" : "NO") << endl;
        else if (m % 2 == 0)
            cout << ((k - m / 2) % 2 == 0 && k >= m / 2 ? "YES" : "NO") << endl;
        else if (n % 2 == 0)
            cout << (k % 2 == 0 && k <= (m - 1) * n / 2 ? "YES" : "NO") << endl;
        else
            cout << "err, what's wrong with this data?" << endl;
    }

    return 0;
}