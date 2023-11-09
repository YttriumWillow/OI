#include <iostream>
#include <algorithm>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

i64 L, R; string s;
i64 f[20][20][20];
i64 nxt[20], a[20], cnt, len;

inline i64 dfs(i64 n, i64 p, i64 sum, bool fu, bool f0)
{
	if (n < 0) { return sum; }
	if (not fu and not f0 and ~f[n][p][sum]) return f[n][p][sum];

	i64 m = fu ? a[n] : 9; i64 res = 0;

	rep (i, 0, m)
	{
		i64 c1 = p, c2 = sum;
		if (not f0 or i)
		{
			while (c1 and s[c1] - '0' != i) c1 = nxt[c1];
			if (s[c1] - '0' == i) ++c1;
			if (c1 == len) ++c2, c1 = nxt[c1];
		}
		res += dfs(n - 1, c1, c2, fu and i == m, f0 and i == 0);
	}
	if (not fu and not f0)
		return f[n][p][sum] = res;
	return res;
}

inline i64 calc(i64 x)
{
	cnt = 0;
	while (x) { a[cnt++] = x % 10; x /= 10; }
	return dfs(cnt - 1, 0, 0, 1, 1);
}

inline void solve()
{
	memset(f, -1, sizeof f);

	cin >> s >> L >> R;

	len = s.size(); // s = '#' + s; 

	rep (i, 0, len) nxt[i] = 0;

	for (int i = 2, j = 0; i <= len; ++i)
	{
		while (j and s[j] != s[i - 1]) j = nxt[j];
		if (s[j] == s[i - 1]) ++j;
		nxt[i] = j;
	}

	cout << calc(R) - calc(L - 1) << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}