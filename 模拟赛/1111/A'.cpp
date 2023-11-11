#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 2e3 + 10;

int n, m; i64 res;
int a[N][N], sum[N][N];

inline int query(int i, int j, int x, int y) { return sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]; }

int main()
{
	file("wu");

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n) rep (j, 1, m)
	{
		cin >> a[i][j];
		sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
	rep (i, 1, n) rep (j, 1, m)
	{
		if (!a[i][j]) continue;
		int b = 1, x = i, y = j;
		while (x <= n && y <= m && query(i, j, x, y) == b * b) ++x, ++y, ++b;
		if (x > n or y > m or x <= i or y <= j) continue;
		int p = x - 1, q = y - 1;
		while (x <= n)
		{
			while (y <= m && sum[x][y] - sum[i - 1][y] - sum[x][j - 1] == sum[p][q] - sum[i - 1][q] - sum[p][j - 1]) ++y, ++res;
			y = q + 1, ++x;
			if (sum[x][y] - sum[i - 1][y] - sum[x][j - 1] != sum[p][q] - sum[i - 1][q] - sum[p][j - 1]) break;
		}
	}
	cout << res << endl;
	return 0;
}