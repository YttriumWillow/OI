#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 11;

int n, a[N][N];
int f[N][N][N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) rep (j, 1, n)
		cin >> a[i][j];

	rep (i, 1, n) rep (j, 1, n)
		rep (x, 1, n) rep (y, 1, n)
		{
			f[i][j][x][y] = max({ f[i - 1][j][x - 1][y], f[i - 1][j][x][y - 1], f[i][j - 1][x - 1][y], f[i][j - 1][x][y - 1]  }) + a[i][j] + a[x][y];
			if (i == x and j == y) f[i][j][x][y] -= a[i][j];
		}

	cout << f[n][n][n][n] << endl;

	return 0;
}