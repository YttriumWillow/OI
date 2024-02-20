#include <iostream>

#define i64 long long
#define u64 unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 20;
const int M = 1e5 + 10;

int n, m;
char x[M];
int a[N][M];
u64 f[M], ans;

signed main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", x);
		for (int j = 1; j <= m; ++j)
			a[i][j] = x[j - 1] - '0';
	}

	for (u64 i = 0, f = 0; i < (1ull << n); ++i, f = 0)
	{
		for (int j = 1, st = 0; j <= m; ++j, st = 0)
		{
			for (int k = 1; k <= n; ++k)
				st += (bool)( a[k][j] ? (!(i >> (k - 1) & 1ull)) : (i >> (k - 1) & 1ull) );
			if (st <= (n >> 1)) st = n - st;
			f += st;
		}
		ans = max(ans, f);
	}

	printf("%lld\n", n * m - ans);

	return 0;
}