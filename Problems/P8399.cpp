#include <iostream>

#include <cstring>
#include <vector>

#define i64 long long

using namespace std;

const int N = 5e6 + 10;
const int inf = 0x3f3f3f3f;

int n, now, o = 1, pay = 2;
int dp[N][5], cost[N << 1];
vector<int> g[N]; string p;

inline int dfs(int u, int pre, int st)
{
	int &ret = dp[u][st];
	if (ret != -1) return ret;
	if (p[u] == 'Y' or st == o)
	{
		int ans = cost[u];
		for (auto x : g[u])
		{
			if (x == pre) continue;
			int cur = dfs(x, u, o);
			if (cur == inf) { ans = inf; break; }
			else ans += cur;
		}
		if (st != pay)
		{
			int ans1 = 0;
			for (auto x : g[u])
			{
				if (x == pre) continue;
				int cur = dfs(x, u, now);
				if (cur == inf) { ans1 = inf; break; }
				else ans1 += cur;
			}
			ans = min(ans, ans1);
		}
		return ret = ans;
	}
	else
	{
		if ((int)g[u].size() == 1 and g[u][0] == pre) return ret = inf;
		int sum = 0;
		int ans = inf;
		for (auto x : g[u])
		{
			if (x == pre) continue;
			int cur = dfs(x, u, o);
			sum += cur;
		}
		for (auto x : g[u])
		{
			if (x == pre) continue;
			int cur1 = dfs(x, u, o);
			int cur2 = dfs(x, u, pay);
			if (cur2 == inf) continue;
			ans = min(ans, sum - cur1 + cur2);
		}
		if (ans != inf) ans += cost[u];
		if (st != pay)
		{
			int sum2 = 0;
			int ans2 = inf;
			bool f = 1;
			for (auto x : g[u])
			{
				if (x == pre) continue;
				int cur = dfs(x, u, now);
				if (cur != inf) sum2 += cur;
				else { f = 0; break; }
			}
			if (f)
			{
				for (auto x : g[u])
				{
					if (x == pre) continue;
					int cur1 = dfs(x, u, now);
					int cur2 = dfs(x, u, pay);
					if (cur1 == inf or cur2 == inf) continue;
					ans2 = min(ans2, sum2 - cur1 + cur2);
				}
				ans = min(ans, ans2);
			}
		}
		return ret = ans;
	}
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 1, a, b; i < n; ++i)
	{
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> p;
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	cout << dfs(0, -1, now) << endl;
}