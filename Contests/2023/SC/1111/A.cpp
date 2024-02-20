#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 2e3 + 10;

int n, m;
int a[N][N], sum[N][N];
int f[N][N];
int g[N][N];
int h[N][N][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, n) rep (j, 1, m)
	{
		cin >> a[i][j];
		sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
	}

	rep (i, 1, n) rep (j, 1, m)
	{
		if (a[i][j]) h[i][j][0] = h[i][j][1] = 1;
		if (h[i - 1][j][0]) h[i][j][0] += h[i - 1][j][0] + 1;
		if (h[i][j - 1][1]) h[i][j][1] += h[i][j - 1][1] + 1; 
	}

	return 0;
}