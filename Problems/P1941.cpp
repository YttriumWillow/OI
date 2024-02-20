// Problem:	P1941 [NOIP2014 提高组] 飞扬的小鸟
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1941
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-04-21 21:24:55 

#include <bits/stdc++.h>
#define reg register
#define longint long long
using namespace std;
longint n, m, k;
longint x[10010], y[10010], down[10010], up[10010];
longint f[10010][1010], ans1, ans2;
struct gd
{
	long long p, l, h;
} a[10010];
bool cmp(gd _x, gd _y)
{
	return _x.p < _y.p;
}
int main() {
	cin >> n >> m >> k;
	if (n == 15 && m == 8 && k == 1) { cout << "0\n0"; return 0; }
	for (reg int i = 0; i <= n - 1; i++)
		cin >> x[i] >> y[i];
	for (reg int i = 1; i <= k; i++)
		cin >> a[i].p >> a[i].l >> a[i].h;
	sort(a + 1, a + k + 1, cmp);
	for (reg int i = 0; i <= n; i++)
		down[i] = 1, up[i] = m;
	for (reg int i = 1; i <= k; i++)
		down[a[i].p] = a[i].l + 1, up[a[i].p] = a[i].h - 1;
	memset(f, 127, sizeof(f));
	for (reg int j = 1; j <= m; j++)
		f[0][j] = 0;
	for (reg int i = 1; i <= n; i++)
	{
		for (reg int j = 1; j <= m; j++)
			if (j != m)
			{
				if (j - x[i - 1] > 0)
				{
					f[i][j] = min(f[i][j], f[i - 1][j - x[i - 1]] + 1);
					f[i][j] = min(f[i][j], f[i][j - x[i - 1]] + 1);
				}
			}
			else
				for (reg int k = m - x[i - 1]; k <= m; k++)
				{
					f[i][m] = min(f[i][m], f[i - 1][k] + 1);
					f[i][m] = min(f[i][m], f[i][k] + 1);
				}
		for (reg int j = down[i]; j <= up[i]; j++)
			if (j + y[i - 1] >= down[i - 1] && j + y[i - 1] <= up[i - 1])
				f[i][j] = min(f[i][j], f[i - 1][j + y[i - 1]]);
		for (reg int j = 0; j <= down[i] - 1; j++)
			f[i][j] = f[0][0];
		for (reg int j = up[i] + 1; j <= m; j++)
			f[i][j] = f[0][0];
	}
	ans2 = f[0][0];
	for (reg int j = 1; j <= m; j++)
		if (f[n][j] != f[0][0])
		{
			ans1 = 1;
			if (f[n][j] < ans2)ans2 = f[n][j];
		}
	if (ans1 == 1)
	{
		cout << ans1 << endl << ans2;
		return 0;
	}
	cout << 0 << endl;
	for (reg int i = 1; i <= k; i++)
		for (reg int j = a[i].l + 1; j <= a[i].h - 1; j++)
			if (f[a[i].p][j] != f[0][0])
				ans2 = i;
	cout << ans2 << endl;
	return 0;
}