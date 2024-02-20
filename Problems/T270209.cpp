#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
string str;
int pin; bool flag;
int main()
{
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len; i++)
        if (str[i] == '.')
            flag = true;
    for (int i = len - 1; i >= 0; i--)
        if (str[i] != '0')
        {
            pin = i;
            break;
        }
    if (flag)
        for (int i = 0; i <= pin; i++)
            cout << str[i];
    else
        cout << str;
    return 0;
}