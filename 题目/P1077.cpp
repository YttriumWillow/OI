/*
    FileName: P_1077_NOIP_2012_普及组_摆花.cpp
        + randomhash: f025b183a8735327b5213a7c
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/16 星期天
    Time: 17:38:03
        + Unix Timestamp(second): 1665913083
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

const int mod = 1000007;

int n, m;
int a[110];
int f[110][110];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= min(j, a[i]); k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
    cout << f[n][m] << endl;
    return 0;
}