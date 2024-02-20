#include <bits/stdc++.h>
#define longint long long
#define reg register
using namespace std;
longint n, f[1010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    for (reg int i = 2; i <= n; i++)
    {
        for (reg int j = 1; j <= i / 2; j++)
            f[i] += f[j];
    }
    cout << f[n] << endl;
    return 0;
}