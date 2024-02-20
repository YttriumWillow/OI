#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

int n, q, u, v;
int opt, w, p;
i64 a[N], sum, res;
// bool f1 = 1;

inline void modify(int u, int fa, i64 g)
{
	a[u] += w / g; sum += w / g;
	if (w < g) return;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		modify(v, u, g * p);
	}
}

inline void query(int u, int fa, int f)
{
	if (u == f) return;
	res += a[u];
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		query(v, u, f);
	}
}

int main()
{
	file("street");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> u >> v;
		// ++deg[u], ++deg[v];
		// if (deg[u] > 2 || deg[v] > 2) f1 = 0;
		add(u, v); add(v, u);
	}

	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> u >> w >> p;
			modify(u, 0, 1);
		}
		else
		{
			cin >> u >> v;
			res = 0; query(u, 0, v); cout << res << ' ';
			res = 0; query(v, 0, u); cout << res << endl;
		}
	}

	return 0;
}