#include <iostream>
#include <queue>

// #define int long long 
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

const int N = 1e6 + 10;
const int M = 1e6 + 10;

using namespace std;

int n; i64 sum, a[N], d[N];
bool vis[N];

struct Edge { int v, nxt; };

Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

Edge er[M << 1]; int hr[N], totr;
inline void addr(int u, int v)
{ er[++totr] = { v, hr[u] }; hr[u] = totr; }

inline void SPFA()
{
	queue<int> q;
	for (int i = 1; i <= n; ++i) q.push(i), vis[i] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0; sum = a[u];
		for (int i = h[u]; i; i = e[i].nxt)
			sum += d[e[i].v];
		if (sum < d[u])
		{
			d[u] = sum;
			for (int i = hr[u]; i; i = er[i].nxt)
			{
				int v = er[i].v;
				if (!vis[v]) { q.push(v); vis[v] = 1; }
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, v, m; i <= n; ++i)
	{
		cin >> a[i] >> d[i] >> m;
		while (m--) { cin >> v; add(i, v); addr(v, i); }
	}
	SPFA();
	cout << d[1] << endl;
	return 0;
}