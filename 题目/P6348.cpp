// Problem:       P6348 [PA2011] Journeys
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P6348
// Memory Limit:  500 MB
// Time Limit:    3000 ms
// Created Time:  2023-07-24 14:34:03 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4e5 + 10;
const int M = 1e7 + 10;
const int inf = 0x3f3f3f3f;

// Connections
// In Ranges -> A Virtual Point -> Out Ranges

// Indexs
// Tree-in        : 1 ~ 4n
// Tree-out       : 4n + 1 ~ 8n
// Virtual Points : 8n + 1 ~ 8n + 2m

// That's f**king ugly.
// Plz look at the graph U want me to build.
// And carefully look at your f*king problem.
// Won't you realize that it's more awful than the graph?

// R U sure this won't blown up in the data of 2e5 ???
// points in number of 2e6
// at O(nlogn) this will just touch the limit about 4e7
// if U what to blow up my SPFA, i will bless U.
// With the certain kind of way. --fzy

int n, m, s;

struct Edge { int v, w, nxt; } e[M << 2];
int h[N << 4], tot; 
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

int d[N << 4], leaf[N << 4];

#define ls (p << 1)
#define rs (p << 1 | 1)
struct Node { int l, r; } t[N << 2];

inline void build(int p, int l, int r)
{
	add(p, 4 * n + p, 0);
	t[p].l = l; t[p].r = r;
	
	if (l == r) { leaf[l] = 4 * n + p; return; }
	int mid = (l + r) >> 1;
	
	add(p, ls, 0);
	add(p, rs, 0);
	add(4 * n + ls, 4 * n + p, 0);
	add(4 * n + rs, 4 * n + p, 0);
	
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

inline void insert1(int p, int l, int r, int pos)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		add(pos, p, 1);
		add(4 * n + p, pos + 1, 1);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) insert1(ls, l, r, pos);
	if (mid <  r) insert1(rs, l, r, pos);
}
inline void insert2(int p, int l, int r, int pos)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		add(pos + 1, p, 1);
		add(4 * n + p, pos, 1);
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) insert2(ls, l, r, pos);
	if (mid <  r) insert2(rs, l, r, pos);
}

inline void SPFA(int s)
{
	memset(d, 0x3f, sizeof d);
	deque<int> q; q.push_back(s); d[s] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
			{
				d[v] = d[u] + e[i].w;
				e[i].w ? q.push_back(v) : q.push_front(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s;
	build(1, 1, n);
	for (int i = 1, a, b, c, d; i <= m; ++i)
	{
		cin >> a >> b >> c >> d;
		insert1(1, a, b, 8 * n + 2 * i);
		insert2(1, c, d, 8 * n + 2 * i);
	}
	
	SPFA(leaf[s]);
	for (int i = 1; i <= n; ++i)
		cout << (d[leaf[i]] == inf ? -1 : d[leaf[i]] / 2) << endl;
	return 0;
}