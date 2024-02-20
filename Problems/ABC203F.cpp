#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int LOG = 51;
const int inf = 0x3f3f3f3f;

int n, k, maxV, lg;
int a[N], pre[N];
int f[N][LOG];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	maxV = a[n]; lg = __lg(maxV) + 1;
	for (int i = 1; i <= n; ++i)
		pre[i] = upper_bound(a + 1, a + n + 1, (a[i] >> 1)) - a - 1;

	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		f[i][0] = f[i - 1][0] + 1;
		for (int j = 1; j <= lg; ++j)
			f[i][j] = min(f[i - 1][j] + 1, f[pre[i]][j - 1]);
	}

	for (int i = 0; i <= lg; ++i)
		if (f[n][i] <= k)
			cout << i << ' ' << f[n][i] << endl, exit(0);

	return 0;
}