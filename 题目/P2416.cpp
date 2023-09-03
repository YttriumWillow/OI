// Problem:       P2416 泡芙
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2416
// Memory Limit:  256 MB
// Time Limit:    2000 ms
// Created Time:  2023-06-30 21:23:01 

#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
using namespace std;

const int N = 3e5 + 10;
const int M = 3e5 + 10;

int n, m;
struct Edge
{
	int u, v, w, nxt; Edge() { }
	Edge(int u, int v, int w, int nxt): u(u), v(v), w(w), nxt(nxt) {}
} e[M << 1], t[M << 1];
int head[N], tot = 1;
int ht[N]; tre = 1;
inline void addedge(int u, int v, int w)
{
	e[++tot] = Edge(u, v, w, head[u]);
	head[u] = tot;
}
inline void addtree(int u, int v, int w)
{
	t[++tre] = Edge(u, v, w, ht[u]);
	ht[u] = tre;
}
inline void build()
{
	for (int i = 1; i <= m; ++i)
		if (dcc[e[i << 1].u] != dcc[e[i << 1].v])
			addtree(dcc[e[i << 1].u], dcc[e[i << 1].v])
	
}
inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v])
				b[i] = b[i ^ 1] = 1;
		}
		else if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}
inline void dfs(int u)
{
	dcc[u] = dcccnt;
	for (int i = head[u]; i; i = e[i].ext)
	{
		int v = e[i].v;
		if (!b[i] && !dcc[v]) dfs(v);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z;
		addedge(x, y, z);
		addedge(y, x, z);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			++dcccnt, dfs(i);
	for (int i = 1; i <= q; ++i)
	{
		cin >> s >> t;
		cout << query(s, t) << endl;
	}
	return 0;
}