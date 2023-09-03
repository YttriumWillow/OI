#include <iostream>
using namespace std;

int f[110][15];

int main() {
    for (int n = 1; n <= 100; n++)
    {
        for (int m = 1; m <= 100; m++)
        {
            for (int i = 1; i <= n; i++) f[i][1] = i;
            for (int i = 1; i <= m; i++) f[0][i] = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 2; j <= m; j++)
                {
                    f[i][j] = INT_MAX;
                    for (int k = 1; k <= i; k++)
                        f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
                }
            cout << f[n][m] << ' ';
        }
        cout << endl;
    }
    return 0;
}