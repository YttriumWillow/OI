/*
    FileName: U_252570_星环防御工事.cpp
        + randomhash: 59e4aa1bcd44c40e7cf224d8
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/16 星期天
    Time: 11:19:00
        + Unix Timestamp(second): 1665890340
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

longint n, k, d, m, ans, maxday;

longint a[300010];
longint b[300010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (reg int i = 1; i <= n; i++)
    {
        cin >> d >> m;
        a[d] += m;
        maxday = max(maxday, d);
    }
    for (reg int i = 1; i <= maxday + 1; i++)
    {
        if (b[i] > k)
        {
            b[i + 1] += a[i]; // 先处理昨天留下的
            ans += k;
        }
        else
        {
            longint leavetoday = k - b[i]; // 今天剩下处理能力
            ans += b[i];
            if (a[i] > leavetoday)
            {
                b[i + 1] += a[i] - leavetoday; // 如果不能处理完今天的
                ans += leavetoday;
            }
            else
                ans += a[i]; // 否则全处理掉
        }
    }
    cout << ans << endl;
    return 0;
}
