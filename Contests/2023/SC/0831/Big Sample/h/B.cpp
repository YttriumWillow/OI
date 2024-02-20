#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int k, p[30];
i64 R, cnt, ans;

inline void dfs(int i, i64 val)
{
	if (i > k)
	{
		ans = max(ans, val);
		++cnt; return;
	}

	__int128 nxt = val;
	for (int j = 0; j <= 100; ++j)
	{
		if (nxt > R) break;
		dfs(i + 1, nxt);
		nxt *= p[i];
	}
}

int main()
{
	// freopen("h.in", "r", stdin);
	// freopen("h.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k >> R;
	for (int i = 1; i <= k; ++i)
		cin >> p[i];
	sort(p + 1, p + k + 1, greater<int>());
	dfs(1, 1);
	cout << ans << endl << cnt << endl;
	return 0;
}