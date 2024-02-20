// Problem:       P3084 [USACO13OPEN] Photo G
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P3084
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-08-04 11:43:33 

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n, m, faq;
int d[N], cnt[N];
bool vis[N];

struct Edge { int v, w, nxt; };
Edge e[M << 1]; int tot, h[N];
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

inline int SPFA(int s)
{
	fill(d + 1, d + n + 1, inf);
	deque<int> q; q.push_back(s);
	vis[s] = 1; d[s] = 0;
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
					if (++cnt[v] > n) return -1;
					if (++faq > 11451419) return -1;
					!q.empty() && d[v] < d[q.front()] ? q.push_front(v) : q.push_back(v);
				}
			}
		}
	}
	return d[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		add(u - 1, v,  1);
		add(v, u - 1, -1);
	}
	for (int i = 1; i <= n; ++i)
	{
		add(i - 1, i, 1);
		add(i, i - 1, 0);
	}
	cout << SPFA(0) << endl;
	
	return 0;
}