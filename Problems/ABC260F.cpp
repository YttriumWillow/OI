#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4e5 + 10;
const int M = 3e5 + 10;
const int T = 3e3 + 10;

int s, t, m;
int col[T][T];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> t >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		add(u, v);
	}
	for (int u = 1; u <= s; ++u)
	{
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v1 = e[i].v;
			for (int j = h[u]; j; j = e[j].nxt)
			{
				int v2 = e[j].v;

				if (v1 == v2) continue;
				if (col[v1 - s][v2 - s])
				{
					cout << u << ' ' << v1 << ' ' << col[v1 - s][v2 - s] << ' ' << v2 << endl;
					exit(0);
				}
				else col[v1 - s][v2 - s] = u;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}