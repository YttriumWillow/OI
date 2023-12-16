#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;

struct Graph
{
	struct Edge { int v, w, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, int w)
	{ e[++tot] = { v, w, h[u] }; ++tot; }
} G;

namespace HLD
{
int fa[N];
int dfn[N];
int top[N];

inline void dfs1(int u)
{
	dep[u] = dep[fa[u]] + 1;
	
}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 2, n)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G.add(u, v, w);
	}



	return 0;
}