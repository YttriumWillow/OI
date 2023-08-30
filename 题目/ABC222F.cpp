#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4e5 + 10;
const int M = 4e5 + 10;

int n, m, S, T;
i64 d[N], ds[N], dt[N];

struct Edge { int v, w, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa, i64 *d)
{
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		d[v] = d[u] + e[i].w;
		dfs(v, u, d);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, u, v, w; i < n; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
		add(i, i + n, d[i]);
		add(i + n, i, d[i]);
	}
	dfs(1, 0, d);
	S = max_element( d + 1,  d + 2 * n + 1) -  d; dfs(S, 0, ds);
	T = max_element(ds + 1, ds + 2 * n + 1) - ds; dfs(T, 0, dt);
	for (int i = 1; i <= n; ++i)
	{
		if (i == S - n)
			cout << dt[i] << endl;
		else if (i == T - n)
			cout << ds[i] << endl;
		else
			cout << max(dt[i], ds[i]) << endl;
	}
	return 0;
}