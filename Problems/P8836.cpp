/*
    FileName: P_8836_传智杯_3_决赛_打牌.cpp
        + randomhash: 8dfa795ac5682837fa8d6a61
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/14 星期一
    Time: 20:17:21
        + Unix Timestamp(second): 1668428241
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

const int PLAYER_NUMBER = 3;

int n, m, x;

struct Player
{
    int all;
    int card[51]; // 用桶存储
    bool discard(int cardIndex, int cardNumber) // 打出 cardNumber 张 号码为 cardIndex 的牌
    {
        card[cardIndex] -= cardNumber;
        all -= cardNumber;
        if (cardNumber < 0) return false;
    }
} p[4];

struct Round
{
    int player, cardIndex, cardNumber;
} r[2501];


int main()
{
    scanf("%d%d", &n, &m);

    for (reg int i = 1; i <= PLAYER_NUMBER; ++i)
        for (reg int j = 1; j <= n; ++j)
            scanf("%d", &x), ++p[i].card[x], p[i].all += x;
    
    for (reg int i = 1; ; ++i)
    {
        
    }
    return 0;
}