#include <iostream>

#include <set>
#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int maxlength, ans;
string n = " ", x, p;
set<string> s[210];
bool f[200010] = { 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> x && x != ".")
    {
        s[x.size()].insert(x);
        maxlength = max(maxlength, int(x.size()));   // 我突然发现 string::size() 是 O(1) 的
    }
    while (cin >> x)
    {
        n += x;
    }
    for (int i = 1; i < int(n.size()); i++)
    {
        for (int l = min(maxlength, i); l >= 1; l--)
        {
            p = n.substr(i - l + 1, l);
            if (s[l].count(p) && f[i - l])
            {
                ans = i;
                f[i] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}