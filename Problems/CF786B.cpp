// Problem:       Legacy
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/CF786B
// Memory Limit:  250 MB
// Time Limit:    2000 ms
// Created Time:  2023-07-26 11:11:58 

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e6 + 10;
const int M = 4e7 + 10;
const int inf = 0x3f3f3f3f;

struct Edge { int v, w, nxt; };
Edge e[M]; int h[N], tot;
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

int n, q, s;
int opt, u, v, l, r, w;
int leaf[N], d[N];
bool vis[N];

struct Node { int l, r; } t[N];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void build(int p, int l, int r)
{
	add(p, 4 * n + p, 0);
	// add(4 * n + p, p, 0);
	
	t[p].l = l, t[p].r = r;
	if (l == r) { leaf[l] = p; return; }
	int mid = (l + r) >> 1;
	
	add(p, ls, 0);
	add(p, rs, 0);
	add(4 * n + ls, 4 * n + p, 0);
	add(4 * n + rs, 4 * n + p, 0);
	
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

inline void insert1(int u, int v, int w)
{
	add(4 * n + u, v, w);
}

inline void insert2(int p, int l, int r, int v, int w)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		add(v, p, w);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) insert2(ls, l, r, v, w);
	if (mid  < r) insert2(rs, l, r, v, w);
}

inline void insert3(int p, int l, int r, int v, int w)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		add(4 * n + p, v, w);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) insert3(ls, l, r, v, w);
	if (mid  < r) insert3(rs, l, r, v, w);
}

#define Pii pair<int, int>

inline void dijkstra(int s)
{
	priority_queue<Pii, vector<Pii>, greater<Pii>> q;
	fill(d + 1, d + 8 * n + 1, inf); d[s] = 0;
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)	
			{
				d[v] = d[u] + e[i].w;
				q.push({ d[v], v });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q >> s;
	build(1, 1, n);
	for (int i = 1; i <= q; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> u >> v >> w;
			insert1(u, v, w);
		}	
		if (opt == 2)
		{
			cin >> u >> l >> r >> w;
			insert2(1, l, r, leaf[u], w);
		}
		if (opt == 3)
		{
			cin >> v >> l >> r >> w;
			insert3(1, l, r, leaf[v], w);
		}
	}
	dijkstra(leaf[s]);
	for (int i = 1; i <= n; ++i)
		cout << (d[leaf[i]] == inf ? -1 : d[leaf[i]] / 2) << ' ';
	return 0;
}