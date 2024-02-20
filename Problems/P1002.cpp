#include <bits/stdc++.h>
#define longint long long
#define reg register
using namespace std;
longint a[114][114];
longint n, m, x, y;
int main()
{
    cin >> n >> m >> x >> y;
    for (reg int i = 0; i <= n; i++)
        for (reg int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0) a[i][j] = 1;
            else if (i == 0) a[i][j] = a[i][j - 1];
            else if (j == 0) a[i][j] = a[i - 1][j];
            else
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            if (
                (i == x + 2 && j == y + 1) || (i == x + 1 && j == y + 2) ||
                (i == x - 2 && j == y + 1) || (i == x - 1 && j == y + 2) ||
                (i == x + 2 && j == y - 1) || (i == x + 1 && j == y - 2) ||
                (i == x - 2 && j == y - 1) || (i == x - 1 && j == y - 2) ||
                (i == x && j == y)
                )
                a[i][j] = 0;

        }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << a[i][j] << "\t";
        cout << '\n';
    }
    cout << a[n][m] << endl;
    return 0;
}