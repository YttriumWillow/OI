#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e3 + 10;

int n, a[N], re[N];
i64 f[N][N];
i64 g[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] -= i, re[i] = a[i];
	}
	sort(re + 1, re + 1 + n);

	// 初始化写法和 n^3 做法略有不同，但本质一样。
	for (int i = 1; i <= n; ++i)
		f[1][i] = abs(a[1] - re[i]);
	for (int i = 2; i <= n; ++i)
	{
		g[i] = 2e18;
		for (int j = 1; j <= n; ++j)
		{
			g[i] = min(g[i], f[i - 1][j]);
			f[i][j] = g[i] + abs(a[i] - re[j]);
		}
	}

	puts("");
	rep (i, 1, n) rep (j, 1, n)
		printf("%5lld", (j != n) ? f[i][j] : g[i]), putchar(" \n"[j == n]);
	

	return 0;
}
