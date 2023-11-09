#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

bool flag;
int col[N];
int n, m, k, idx, t;
int h[N], e[M], ne[M], ly[M], ry[M];

inline void add(int a, int b, int c, int d)
{
	e[idx] = b;
	ly[idx] = c;
	ry[idx] = d;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}

inline void dfs(int u, int la, int opt)
{
	if(!flag) return ;
	col[u] = opt;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(t < ly[i] || t >= ry[i]) continue;
		if(j == la) continue;
		if(col[j] == col[u]) {flag = 0; break;}
		if(col[j] == -1) dfs(j, u, opt ^ 1);
	}
}

void solve1()
{
	for(int i = 0; i < k; ++ i)
	{
		t = i; flag = 1;
		memset(col, -1, sizeof col);
		for(int i = 1; i <= n; ++ i)
		{
			if(col[i] == -1) dfs(i, 0, 0);
			if(!flag) {cout << "No\n"; break;}
		}
		if(flag) cout << "Yes\n";
	}
}

void solve2()
{
	flag = 1, t = ly[1];
	memset(col, -1, sizeof col);
	for(int i = 0; i < ly[1]; ++ i)
		cout << "Yes\n";
	for(int i = 1; i <= n; ++ i)
	{
		if(col[i] == -1) dfs(i, 0, 0);
		if(!flag)
		{
			for(int i = ly[1]; i < ry[1]; ++ i)
				cout << "No\n";
			break;
		}
	}
	if(flag)
	{
		for(int i = ly[1]; i < ry[1]; ++ i)
		 cout << "Yes\n";
	}
	for(int i = ry[1]; i < k; ++ i) cout << "Yes\n";
}

int main()
{
	freopen("yume.in", "r", stdin);
	freopen("yume.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; ++ i)
	{
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		add(u, v, l ,r), add(v, u, l ,r);
	}
	if(n <= 5000 && m <= 5000 && k <= 5000) solve1();
	else solve2();
}