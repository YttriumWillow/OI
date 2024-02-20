#include <bits/stdc++.h>
#define longint long long
#define reg register
using namespace std;
int n, x, T, a;
bool flag;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> x; flag = true;
        for (reg int i = 1; i <= n; i++)
        {
            cin >> a;
            if ( !(x % a == 0 && a * x <= 0) )
                flag = false;
        }
        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
/*
泣かないで わたしの恋心
涙はお前にゃ似合わない
ゆけ ただゆけ
いっそわたしがゆくよ
ああ 心が笑いたがっている

不要哭泣啊 我的爱恋之心
眼泪和 "你" 并不相配
走吧 只是向前
我已下定决心就这样大步向前
啊啊 虽然内心没有了笑容
*/