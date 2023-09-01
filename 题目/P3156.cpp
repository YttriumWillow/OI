#include<bits/stdc++.h>
using namespace std;
int n, m, a[2000001], b;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> b;
        cout << a[b] << endl;
    }
    return 0;
}