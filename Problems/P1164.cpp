#include <iostream>


#define longint long long
#define reg register
#define qwq puts("fzy qwq~");

using namespace std;

int a[101], f[101][10001];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i];
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
        {
            if (j > a[i])
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            if (j < a[i])
                f[i][j] = f[i - 1][j];
            if (j == a[i])
                f[i][j] = f[i - 1][j] + 1;
        }
    cout << f[n][m] << endl;
    return 0;
}
