#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, cnt; i64 res;
i64 a[N], g[N], l[N];

inline void solve()
{
	res = cnt = 0;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i]; res = max(res, a[i]);
		for (int j = 1; j <= cnt; ++j)
		{
			g[j] = __gcd(g[j], a[i]);
			if (g[j] == g[j - 1])
			{
				for (int k = j; k < cnt; ++k)
					g[k] = g[k + 1], l[k] = l[k + 1];
				--cnt; --j;
			}
			else res = max(res, (i - l[j] + 1) * g[j]);
		}
		g[++cnt] = a[i]; l[cnt] = i;
	}

	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}