#include <iostream>

#include <deque>
#include <ctime>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Pii pair<int, int>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct Edge { int v, w, nxt; };
Edge e[M << 2]; int h[N], tot;

inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }, h[u] = tot; }

int n, m, k;
int d[N];
bool vis[N];

inline void SPFA(int s)
{
	deque<int> q; q.push_back(s);
	fill(d, d + n + 1, inf);
	d[0] = 0; vis[0] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		vis[u] = 0;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
			{
				d[v] = d[u] + e[i].w;
				if (!vis[v])
				{
					(d[v] < d[q.front()]) ? ((rand() % 2) ? q.push_front(v) : q.push_back(v)) : q.push_back(v);
					// q.push_back(v);
					vis[v] = 1;
				}
			}
		}
	}
}

inline void dijkstra(int s)
{
	priority_queue<Pii, vector<Pii>, greater<Pii>> q;
	fill(d, d + n + 1, inf); d[s] = 0; q.push({ 0, s });
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
			{
				d[v] = d[u] + e[i].w;
				q.push({ d[v], v });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	srand(time(0));

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		add(i - 1, i, 1);
		add(i, i - 1, 0);
	}
	for (int i = 1, l, r, c; i <= m; ++i)
	{
		cin >> l >> r >> c;
		add(l - 1, r, r - l + 1 - c);
	}
	dijkstra(0);
	for (int i = 1; i <= n; ++i)
		cout << !(d[i] - d[i - 1]) << ' ';
	return 0;
}