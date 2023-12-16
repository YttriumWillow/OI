#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1010;
const int inf = 0x3f3f3f3f;

int n, m;
struct edge { int v, w; } e[N];
int h[N], tot;
inline void add(int x, int y, int z)
{ e[++tot] = { y, z }; h[x] = tot; }

int in[N], out[N], Min, cnt;

inline void dfs(int u)
{
	if (!h[u]) return;
	Min = min(Min, e[h[u]].w);
	cnt = e[h[u]].v;
	dfs(e[h[u]].v);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		++out[a]; ++in[b];
	}

	int res = 0;
	rep (i, 1, n)
		if (!in[i] && out[i]) ++res;
	cout << res << endl;

	rep (i, 1, n)
	{
		Min = inf;
		if (!in[i] && out[i])
		{
			dfs(i);
			cout << i << ' ' << cnt << ' ' << Min << endl;
		}
	}
	return 0;
}
