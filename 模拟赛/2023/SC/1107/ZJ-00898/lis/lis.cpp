#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 510;
const int inf = 0x3f3f3f3f;

int n, a[N];
int f[N][N], g[N][N];
int res[N * N];

// f[i][j][k] 表示到 ith 数，修改了 j 个元素，最后一个元素是 k 的最小修改代价。
// f[i][j][k] = f[i - 1][j - 1][w] + abs(a[i] - w)
// ws** 我中午没睡觉
// 调 1h 发现滚掉一维初始化就对了
// 三维初始化挂飞了的 ** 
// wgswd wgswd wgswd

int main()
{
	file("lis");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> a[i];

	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;

	rep (i, 1, n)
	{
		rep (j, 0, n) rep (k, 0, n) g[j][k] = inf;
		rep (j, 1, n) rep (k, 1, n)
			{ g[j][k] = min(g[j][k], f[j - 1][k - 1]); }
		rep (k, 1, n) rep (j, 1, n)
			{ g[j][k] = min(g[j][k], g[j - 1][k]); }
		rep (j, 1, n) rep (k, 0, n) 
			{ f[j][k] = min(f[j][k], g[j][k] + abs(j - a[i])); }
	}
	rep (j, 0, n) rep (k, 0, n)
		if (f[j][k] <= n * n)
			res[f[j][k]] = max(res[f[j][k]], k);
	rep (i, 0, n * n)
	{
		res[i] = max(res[i - 1], res[i]);
		cout << res[i] << ' ';
	}
	return 0;
}