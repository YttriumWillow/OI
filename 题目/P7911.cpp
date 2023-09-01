/*
    FileName: P_7911_CSP-J_2021_网络连接.cpp
        + randomhash: f28147772c836abeea564c88
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/24 星期一
    Time: 19:27:25
        + Unix Timestamp(second): 1666610845
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <map>
#include <cstring>
#include <sstream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n;
string c, ip;
map<string, int> mp;

bool check(string x)
{
    int part1, part2, part3, part4, port;
    string format = "%d.%d.%d.%d:%d";
    int p = sscanf(x.c_str(), format.c_str(), &part1, &part2, &part3, &part4, &port);
    if (p != 5) return false;
    if (part1 < 0 || part1 > 255) return false;
    if (part2 < 0 || part2 > 255) return false;
    if (part3 < 0 || part3 > 255) return false;
    if (part4 < 0 || part4 > 255) return false;
    if (port < 0 || port > 65535) return false;
    stringstream s;
    s << part1 << '.' << part2 << '.' << part3 << '.' << part4 << ':' << port;
    return s.str() == x;
}

int main()
{
    cin >> n;
    for (reg int i = 1; i <= n; ++i)
    {
        cin >> c >> ip;
        if (!check(ip)) cout << "ERR" << endl;
        else if (c == "Server")
            if (mp[ip] != 0)
                cout << "FAIL" << endl;
            else
            {
                mp[ip] = i;
                cout << "OK" << endl;
            }
        else
            if (!mp.count(ip))
                cout << "FAIL" << endl;
            else
                cout << mp[ip] << endl;
    }
    return 0;
}