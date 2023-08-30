#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int M = 1e5 + 10;

int n, m, p;
i64 s[M];
i64 cnt[70];
i64 ans, pos = 1;

int main()
{
	// freopen("nim.in", "r", stdin);
	// freopen("nim.out", "w", stdout);

	cin >> n >> m; ++n;

	for (int i = 1; i <= m; ++i)
	{
		cin >> s[i];
		for (int j = 0; j <= 60; ++j)
		{
			if ((1ll << j) > s[i]) break;
			if ((1ll << j) & s[i]) ++cnt[j];
		}
	}

	for (int i = 0; i <= 60; ++i)
	{
		cnt[i] += (n / (pos << 1) * pos + max(0ll, n % (pos << 1) - pos));
		pos <<= 1;
		if (cnt[i] == 0) break;
	}

	for (int i = 0; i <= 60; ++i)
		if (cnt[i] & 1)
			p = (1ll << i);

	for (int i = 1; i <= m; ++i)
		if ((p & s[i]) == p)
			++ans;

	ans += (n / (p << 1) * p + max(0ll, n % (p << 1) - p));

	cout << ans << endl;

	return 0;
}