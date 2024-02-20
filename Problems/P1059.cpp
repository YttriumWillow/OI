#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, x;
set<int> s;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    for (auto ans:s)
    {
        cout << ans << ' ';
    }
    return 0;
}