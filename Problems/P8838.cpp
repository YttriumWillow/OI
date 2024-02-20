/*
    FileName: P_8838_传智杯_3_决赛_面试.cpp
        + randomhash: 1654235d9ae4261583f7f81b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/14 星期一
    Time: 21:02:47
        + Unix Timestamp(second): 1668430967
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

// czy十年阳寿换最优解！！！
#include <iostream>
using namespace std;
int n, k, a[7], b[7], ans[7];
bool vis[7], flag;
inline void dfs(int i)
{
    if (i > k)
    {
        for (int i = 1; i <= k; ++i)
            printf("%d ", ans[i]);
        flag = true;
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (a[j] >= b[i] && vis[j] == 0)
        {
            vis[j] = 1; ans[i] = j;
            dfs(i + 1); if (flag) return;
            vis[j] = 0;
        }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &b[i]);
    dfs(1);
    if (!flag) printf("-1\n");
    return 0;
}