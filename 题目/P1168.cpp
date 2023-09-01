#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
vector<longint> a;
longint n, x;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a.insert(upper_bound(a.begin(), a.end(), x), x);
        if (i % 2 == 1)
            cout << a[(i - 1) / 2] << endl;
    }
    return 0;
}