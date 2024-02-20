#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, res;
int di[N], dj[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa, int *d)
{
	d[u] = d[fa] + 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u, d);
	}
}

int main()
{
	file("ringcount");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 2, x; i <= n; ++i)
		cin >> x, add(x, i), add(i, x);

	for (int i = 1; i <= n; ++i)
	{
		dfs(i, 0, di);
		for (int j = i + 1; j <= n; ++j)
		{
			dfs(j, 0, dj);
			for (int k = j + 1; k <= n; ++k)
			{
				if (k != i && k != j && di[k] == dj[k] && di[k] == di[j])
					++res;
			}
		}
	}
	cout << res << endl;

	return 0;
}