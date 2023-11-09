#include <cstring>
#include <iostream>

#define int long long

using namespace std;

string s;
int a[20], la[20];
int k, t, top, siz;
int dp[20][20][20];

inline int dfs(int n, int p, int mcnt, bool f1, bool f2)
{
	if (n < 0) { return mcnt == t; }
	if (mcnt > t) return 0;
	if (!f1 && !f2 && dp[n][p][mcnt] != -1) return dp[n][p][mcnt];
	if (f2) mcnt = p = 0;
	int m = f1 ? a[n] : 9, ans = 0;
	for(int i = 0; i <= m; ++ i)
	{
		int c = s[p] ^ 48;
		if(i == c)
		{
			int x = p;
			ans += dfs(n - 1, (p + 1 == siz) ? la[p] + 1 : p + 1, mcnt + (p + 1 == siz ? 1 : 0), f1 && i == m, f2 && (!i));
			// while(x != -1 && la[x] != -1)
				// x = la[x] + 1, ans += dfs(n - 1, x + 1, mcnt, f1 && i == m, f2 && (!i));
		}
		else if(p && i == (s[0] ^ 48)) ans += dfs(n - 1, (siz == 1) ? la[0] + 1 : 1, mcnt + (siz == 1 ? 1 : 0), f1 && (i == m), f2 && (!i));
		else ans += dfs(n - 1, 0, mcnt, f1 && (i == m), f2 && (!i));
	}
	if (!f1 && !f2) dp[n][p][mcnt] = ans;
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
	freopen("number.out", "p", stdout);
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