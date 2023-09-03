/*
    FileName: AT_dp_d_Knapsack_1.cpp
        + randomhash: 467ad79fe8392949e3774ff7
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/22 星期六
    Time: 17:43:08
        + Unix Timestamp(second): 1666431788
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

longint n, W;
longint w[100010], v[100010];
longint f[100010];

int main()
{
    cin >> n >> W;
    for (reg longint i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (reg longint i = 1; i <= n; ++i)
        for (reg longint j = W; j >= w[i]; --j)
            f[j] = max(f[j - w[i]] + v[i], f[j]);
    cout << f[W] << endl;
    return 0;
}