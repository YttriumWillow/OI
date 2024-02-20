#pragma GCC optimize(2)

#include <iostream>

#include <unordered_map>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, cnt, ans;
unordered_map<int, bool> vis;

inline void dfs(int x, int y, int now)
{
	if (now * 10 + x <= n && now * 10 + x != now)
	{
		if (!vis.count(now * 10 + x))
		{
			vis[now * 10 + x] = 1;
			++ans;
		}
		dfs(x, y, now * 10 + x);
	}
	if (now * 10 + y <= n && now * 10 + y != now)
	{
		if (!vis.count(now * 10 + y))
		{
			vis[now * 10 + y] = 1;
			++ans;
		}
		dfs(x, y, now * 10 + y);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i <= 9; ++i)
		for (int j = i; j <= 9; ++j)
			dfs(i, j, 0);
	cout << ans << endl;
	return 0;
}