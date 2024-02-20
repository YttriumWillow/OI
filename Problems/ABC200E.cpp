#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define f(x) ((x <= 2) ? 0ll : 1ll * (x - 1) * (x - 2) / 2ll)
#define calc(x) (f(x) - 3ll * f(x - n) + 3ll * f(x - 2ll * n) - f(x - 3ll * n))

i64 n, k, len, rng;

inline void solve(i64 sum)
{
	for (i64 i = 1; i <= n; ++i)
	{
		i64 uj = min(sum - i - 1, n);
		i64 dj = max(sum - i - n, 1ll);
		if (dj <= uj)
		{
			rng = uj - dj + 1;
			if (k > rng) { k -= rng; continue; }
			else { cout << i << ' ' << dj + k - 1ll << ' ' << sum - i - (dj + k - 1ll) << endl; exit(0); }
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (i64 sum = 3; sum <= 3 * n; ++sum)
	{
		len = calc(sum);
		if (k <= len) solve(sum);
		k -= len;
	}
	return 0;
}