// Problem:      P3403 跳楼机
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3403
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-08-15 20:30:30 

// Problem:      P2491 [SDOI2011] 消防
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2491
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-08-15 19:03:27 

#include <bits/stdc++.h>

#define int long long 
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int M = 3e5 + 10;
const int inf = 0x3f3f3f3f;

i64 H, x, y, z, ans;
int d[N]; bool vis[N];

struct Edge { int v, w, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }, h[u] = tot; }

inline void SPFA(int s)
{
	deque<int> q; q.push_back(s);
	memset(d, 0x3f, sizeof d);
	vis[s] = 1; d[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		vis[u] = 0;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
			{
				d[v] = d[u] + e[i].w;
				if (!vis[v])
				{
					(!q.empty() && d[v] < d[q.front()]) ? q.push_front(v) : q.push_back(v);
					// q.push_back(v);
					vis[v] = 1;
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> H >> x >> y >> z;
	if (x == 1 || y == 1 || z == 1) { cout << H << endl; return 0; }
	
	for (int i = 0; i < x; ++i)
	{
		add(i, (i + y) % x, y);
		add(i, (i + z) % x, z);
	}
	
	SPFA(1);
	
	for (int i = 0; i < x; ++i)
		if (d[i] <= H)
			ans += (H - d[i]) / x + 1;
	
	cout << ans << endl;
	return 0;
}