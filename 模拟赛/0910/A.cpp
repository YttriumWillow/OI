#include <iostream>

#define int long long 
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2010;

int n, m, k, h, w;
char ch[N][N];
int d[N][N], sumd[N][N];
int r[N][N], sumr[N][N];
int res;

signed main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> h >> w >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> ch[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			d[i][j] = (ch[i][j] != ch[i + 1][j]);
			r[i][j] = (ch[i][j] != ch[i][j + 1]);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			sumd[i][j] = sumd[i - 1][j] + sumd[i][j - 1] - sumd[i - 1][j - 1] + d[i][j];
			sumr[i][j] = sumr[i - 1][j] + sumr[i][j - 1] - sumr[i - 1][j - 1] + r[i][j];
		}

	// for (int i = 1; i <= n; ++i)
	// 	for (int j = 1; j <= m; ++j)
	// 		cerr << d[i][j] << "\t\n"[j == m];
	// cerr << endl;

	// for (int i = 1; i <= n; ++i)
	// 	for (int j = 1; j <= m; ++j)
	// 		cerr << r[i][j] << "\t\n"[j == m];

	for (int i = 1; i + h - 1 <= n; ++i)
	{
		for (int j = 1; j + w - 1 <= m; ++j)
		{
			int X = i + h - 1, Y = j + w - 1;

			int totd = sumd[i - 1][j - 1] + sumd[X - 1][Y] - sumd[i - 1][Y] - sumd[X - 1][j - 1];

			int totr = sumr[i - 1][j - 1] + sumr[X][Y - 1] - sumr[i - 1][Y - 1] - sumr[X][j - 1];

			 
		}
	}
	cout << res << endl;
	return 0;
}