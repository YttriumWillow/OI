/*
    FileName: CF_776_B_Sherlock_and_his_girlfriend.cpp
        + randomhash: 77767187e1e83b222d4dc469
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/30 星期三
    Time: 20:57:40
        + Unix Timestamp(second): 1669813060
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

const int maxn = 100010;
int n; bool flag[maxn];

int main()
{
    scanf("%d", &n);
    flag[0] = flag[1] = 1;
    for (int i = 2; i * i <= n + 1; ++i)
        if (!flag[i])
            for (int j = i << 1; j <= n + 1; j += i)
                flag[j] = 1;
    
    printf(n < 3 ? "1\n" : "2\n");
    for (int i = 2; i <= n + 1; ++i)
        printf("%d ", flag[i] + 1);
    return 0;
}
