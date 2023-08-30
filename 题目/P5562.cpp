#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq");

using namespace std;

int n;

int main()
{
    cin >> n;
    cout << n * n / 2 << endl;
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n / 2; ++j)
            cout << i << ' ' << j << ' ' << (i + j - 2) % (n / 2) + 1 << endl;
    for (int i = 1; i <= n / 2; ++i)
        for (int j = 1; j <= n / 2; ++j)
            cout << i + n / 2 << ' ' << j + n / 2 << ' ' << (i + j - 2) % (n / 2) + 1 + n / 2 << endl;
    return 0;
}
