#include <bits/stdc++.h>
#define longint long long
using namespace std;
string str[21];
longint n;
bool cmp(const string &x, const string &y)
{
    return (x + y) > (y + x);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> str[i];
    sort(str + 1, str + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << str[i];
    return 0;
}