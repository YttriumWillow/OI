#include <cstring>
#include <iostream>

#define int long long

using namespace std;

string s;
int a[20], la[20];
int k, t, top, siz;
int dp[20][20][20];

inline int dfs(int u, int w, int sum, bool p, bool b)
{
	if(u < 0)
	{
		if(sum == t) return 1;
		return 0;
	}
	if(sum > t) return 0;
	if(!p && !b && dp[u][w][sum] != -1) return dp[u][w][sum];
	if(b) sum = w = 0;
	int up = p ? a[u] : 9, ans = 0;
	for(int i = 0; i <= up; ++ i)
	{
		int c = s[w] ^ 48;
		if(i == c)
		{
			int x = w;
			ans += dfs(u - 1, (w + 1 == siz) ? la[w] + 1 : w + 1, sum + (w + 1 == siz ? 1 : 0), p && i == up, b && (!i));
			// while(x != -1 && la[x] != -1)
				// x = la[x] + 1, ans += dfs(u - 1, x + 1, sum, p && i == up, b && (!i));
		}
		else if(w && i == (s[0] ^ 48)) ans += dfs(u - 1, (siz == 1) ? la[0] + 1 : 1, sum + (siz == 1 ? 1 : 0), p && (i == up), b && (!i));
		else ans += dfs(u - 1, 0, sum, p && (i == up), b && (!i));
	}
	if(!p && !b) dp[u][w][sum] = ans;
	return ans;
}

inline int d(int x)
{
	top = 0;
	memset(dp, -1, sizeof dp);
	while(x)
	{
		a[top ++ ] = x % 10;
		x /= 10;
	}
	return dfs(top - 1, 0, 0, 1, 1);
}

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int l, r;
	cin >> l >> r >> s >> k;
	siz = s.size();
	memset(la, -1, sizeof la);
	for(int i = 0; i < siz; ++ i)
	{
		if(s[i] == s[0]) la[i] = 0;
		if(s[i] == s[la[s[i - 1]] + 1]) la[i] = la[s[i - 1]] + 1;
	}
	for(t = 0; t <= k; ++ t)
		cout << d(r) - d(l - 1) << ' ';
}