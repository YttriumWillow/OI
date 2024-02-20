#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n, m;
int G[110][110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	memset(G, 0x3f, sizeof G);

	rep (i, 1, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}

	rep (k, 1, n) rep (i, 1, n) rep (j, 1, n)
		G[i][j] = i == j ? 0 : min(G[i][j], G[i][k] + G[k][j]);

	rep (i, 1, n) rep (j, 1, n)
		cout << G[i][j] << " \n"[j == n];

	return 0;
}