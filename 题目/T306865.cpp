// Problem:       T306865 一曲新词酒一杯
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/T306865?contestId=97568
// Memory Limit:  128 MB
// Time Limit:    1000 ms
// Created Time:  2023-05-14 14:15:41 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T, n, m, ans;
int opt, x;
bool vis[200010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n >> m; bool flg = 0; ans = -1;
		cerr << n << ' ' << m << endl;
		fill (vis + 1, vis + n + 1, 0);
		for (reg int i = 1; i <= m; ++i)
		{
			cin >> opt >> x;
			if (opt == 1)
				vis[x] = 1;
			else
			{
				if (vis[x] && !flg)
					ans = i;
			}
		}
		cerr << ": ";
		for (reg int i = 1; i <= n; ++i)
			cerr << vis[i] << " \n"[i == n];
		if (!flg)
		{
			bool faq = 1;
			for (reg int i = 1; i <= n; ++i)
				if (!vis[i])
					{ faq = 0; cerr << i << endl; break; }
			flg = faq;
		}
		if (flg) cout << n << endl;
		else cout << -1 << endl;
	}
	return 0;
}