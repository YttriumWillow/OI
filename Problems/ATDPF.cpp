/*
    FileName: AT_dp_f_LCS.cpp
        + randomhash: 6b9fb26582be2075bbc6aec8
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/21 星期五
    Time: 19:13:05
        + Unix Timestamp(second): 1666350785
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
#define tab '\t'

using namespace std;

string s, t;
int n, m, cnt;
int f[3010][3010];
char ans[3010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> t;
    n = s.size(); m = t.size();

    // LCS 板子
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);

    // 从尾巴上扫回去
    int x = n, y = m;
    cnt = f[n][m];
    while (x != 0 && y != 0)
    {
        if (s[x - 1] == t[y - 1])
        {
            ans[cnt--] = s[x - 1];
            x--; y--;
        }
        else
        {
            if (f[x][y] == f[x - 1][y]) x--;
            if (f[x][y] == f[x][y - 1]) y--;
        }
    }
    for (int i = 1; i <= f[n][m]; i++)
        cout << ans[i];
    return 0;
}