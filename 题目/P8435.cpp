#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot = 1;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt; 
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, u),
			low[v] = min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				++dcccnt; int p;
				do {
					p = st.top(); st.pop();
					res[dcccnt].pb(p);
				} while (p != v);
			}
		}
		if (v != fa)
			low[v] = min(low[u], dfn[v]);
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, m) 
	{
		int u, v;
		cin >> u >> v;
		add(u, v); add(v, u);
	}

	rep (i, 1, n) if (!dfn[i]) tarjan(i, i);

	cout << dcccnt << endl;

	return 0;
}