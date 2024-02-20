/*
    FileName: B_3682_语言月赛_202211_Jewellery.cpp
        + randomhash: 8fce37680646fb8945357b0f
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/03 星期六
    Time: 21:01:12
        + Unix Timestamp(second): 1670072472
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>
#include <map>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n, k, value;
string str;
int cmplist[] = {0, 2000, 1000, 200, 4, 5};
map<string, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (reg int i = 1; i <= n; ++i)
        cin >> str >> value, mp[str] = cmplist[value];
    value = 0;
    for (reg int i = 1; i <= k; ++i)
        cin >> str;
    cout << value << endl;
    return 0;
}