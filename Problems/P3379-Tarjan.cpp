#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e6 + 10;
const int M = 5e6 + 10;

namespace DSU
{
int fa[N];
inline void init(int n) { for (int i = 1; i <= n + 5; ++i) fa[i] = i; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int p, int q) { fa[q] = p; }
}
using namespace DSU;

struct Edge { int v, nxt; };

Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

int n, m, s;
bool vis[N];
int res[N], dep[N];

inline void tarjan(int u, int fa)
{
	vis[u] = 1; dep[u] = dep[fa] + 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		tarjan(v, u);
		merge(u, v);
	}
	/*
	for (int i = qh[u]; i; i = qe[i].nxt)
	{
		int v = qe[i].v;
		if (vis[v])
			res[i + (i & 1 ? 1 : -1)] = res[i] = find(v);
	}
	*/ // 合并答案
	// 那我对每个深度为 dep 的合并一边不就好了
	// 难蚌

	res[dep[u]] = res[dep[u]] ? find(res[dep[u]]) : u;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, x; i <= n; ++i)
	{
		cin >> x;
		add(i, x); add(x, i);
	}
	init(n); tarjan(1, 0);
	for (int i = 1, k; i <= m; ++i)
	{
		cin >> k;
		cout << res[k] << endl;
	}
	return 0;
}