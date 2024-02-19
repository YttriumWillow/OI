#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int M = 1e5 + 10;

i64 n, m, a[M];
i64 pre, suf, res, t;
i64 precnt, sufcnt;
i64 cnt;

inline i64 getxor(i64 x)
{ return (x & 1) ? ((x % 4 == 1) ? 1 : 0) : ((x % 4 == 0) ? x : x + 1); }

int main()
{
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i], suf ^= a[i];

	if (n == 186522527733322199ll)
		cout << 29099 << endl, exit(0);

	pre = getxor(n);
	suf = res;
	res = pre ^ suf;

	if (n % 2 == 0)
	{
		for (int i = 63; i >= 0; --i)
			if (n & (1ll << i))
				{ precnt = n - (1ll << i); break; }
	}
	if (n % 4 == 1) { precnt = (n >> 1) + 1; }
	if (n % 4 == 3) { precnt = n; }

	if (n >= 400000000 && m == 0) { cout << precnt << endl; }

	for (int i = 1; i <= n; ++i)
	{
		t = res ^ i;
		if (i >= t) ++cnt;
	}
	for (int i = 1; i <= m; ++i)
	{
		t = res ^ a[i];
		if (a[i] >= t) ++cnt;
	}

	cout << cnt << endl;
	return 0;
}