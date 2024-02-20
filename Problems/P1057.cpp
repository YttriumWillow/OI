/*
    FileName: P_1057_NOIP_2008_普及组_传球游戏.cpp
        + randomhash: 71cd5b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/15
    Time: 09:44:33
        + Unix Timestamp(second): 1665798273
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

int n, m;
int f[110][110];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; f[0][1] = 1; // 万恶之源
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1) f[i][j] = f[i - 1][n] + f[i - 1][j + 1];
            else if(j == n) f[i][j] = f[i - 1][j - 1] + f[i - 1][1];
            else f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
        }
    }
    cout << f[m][1] << endl;
    return 0;
}