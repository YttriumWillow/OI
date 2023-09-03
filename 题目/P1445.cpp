/*
    FileName: P_1445_Violet_樱花.cpp
        + randomhash: 04bf8ddaca01594b17d77f11
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/02 星期五
    Time: 19:19:22
        + Unix Timestamp(second): 1669979962
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

const longint mod = 1000000007;

longint n, ans = 1;

longint prime[10000010];
void init(longint limit)
{
    for (reg int i = 2; i <= limit; ++i)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= limit; ++j)
        {
            prime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

inline longint count(longint k, longint p)
{
    if (k < p) return 0;
    return k / p + count(k / p, p);
}

int main()
{
    scanf("%lld", &n);
    init(n);

    auto cnt = [](longint k, longint p) -> longint
    {
        if (k < p) return 0;
        return k / p + count(k / p, p);
    };

    for (reg int i = 1; i <= prime[0]; ++i)
        ans = ans * (cnt(n, prime[i]) * 2 + 1) % mod; 
    printf("%lld\n", ans);
    return 0;
}