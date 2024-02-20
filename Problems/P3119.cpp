// Problem:       P3119 [USACO15JAN] Grass Cownoisseur G
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P3119
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-20 15:02:29 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

struct Edge
{
	int v, nxt; Edge() {}
	Edge(int v, int n):
		v(v), nxt(n) {}
} e[M << 1];
int h[N], tot;
inline void addedege(int u, int v)
{ e[++tot] = Edge(v, h[u]); h[u] = tot; }
int n, m;
int dfncnt, scccnt;
int dfn[N], low[N];
int scc[N], siz[N];
bool ins[N], vis[N];

inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	ins[u] = 1, 	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		addedge(u, v);
	}
	return 0;
}