#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
map< string, pair <int, vector<int> > > mp;
string str1, str2;
string arraysize, arrayname;
longint lenstr;
bool stop, isname;
int tonumber(string str)
{
    int len = str.size(), res = 0;
    for (int i = 0; i < len; i++)
        res = res * 10 + (str[i] - '0');
    return res;
}
int value(string str)
{
    int i;
    for (i = 0; str[i] != '['; i++)
        arrayname += str[i];
    int len = str.size();
    for (i += 1; i < len - 1; i++)
        arraysize += str[i];
    if (isdigit(arraysize[0]))
        return tonumber(arraysize);
    else
        return value(arraysize);
    return -1;
}
int main()
{
    while (cin >> str1 >> str2)
    {
        if (str1 == "int")
        {
            int i;
            for (i = 0; str2[i] != '['; i++)
                arrayname += str2[i];
            int len = str2.size();
            for (i += 1; i < len - 1; i++)
                arraysize += str2[i];
            if (isdigit(arraysize[0]))
                mp[arrayname].first = tonumber(arraysize);
            else
                mp[arrayname].first = value(arraysize);
            // cout << mp[arrayname].first << endl;
        }
        else if (str1 == "cout")
        {

        }
        else
        {
            int i;
            for (i = 0; str1[i] != '['; i++)
                arrayname += str1[i];
            int len = str1.size();
            for (i += 1; i < len - 1; i++)
                arraysize += str1[i];
            int targetvalue = value(arraysize);
            if (targetvalue >)
            if (isdigit(arraysize[0]))
                mp[arrayname].second[tonumber(arraysize)] = ;
            else
                mp[arrayname].first = value(arraysize);
        }
    }
    return 0;
}