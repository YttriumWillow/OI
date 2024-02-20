#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

Edge ne[M << 1]; int nh[N], ntot;


inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	st.push(u); ins[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++scccnt;
		do {
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (dfn[u] != low[u]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, m) { int u, v; cin >> u >> v; add(u, v); }

	rep (i, 1, n) if (!dfn[i]) tarjan(i);

	rep (u, 1, n)
	{
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (scc[u] != scc[v])
			{

			}
		}
	}


	return 0;
}