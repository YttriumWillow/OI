#include <iostream>
#include <queue>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define prob "path"

using namespace std;

const int N = 2010;

int n, m;
int l[N], r[N], d[N];
bool vis[N], g[N][N];
i64 ans;

inline void bfs(int s)
{
	r[0] = 1;
	for (int i = 1; i <= n; ++i)
		l[i] = i - 1, r[i] = i + 1;
	fill(vis + 1, vis + n + 1, 0);
	fill(d + 1, d + n + 1, n);
	
	queue<int> q; q.push(s); d[s] = 0;
	
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (int v = r[0]; v <= n; v = r[v])
		{
			if (g[u][v] && !vis[v])
			{
				q.push(v);
				d[v] = d[u] + 1;
				l[r[v]] = l[v];
				r[l[v]] = r[v];
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
		ans += d[i] * d[i];
}
int main()
{
//	freopen(prob".in", "r", stdin);
//	freopen(prob".out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n; char ch;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ch, g[i][j] = (i == j) || (ch - '0');
		
	for (int i = 1; i <= n; ++i)
		bfs(i);	
	
	cout << ans << endl;
	return 0;
}