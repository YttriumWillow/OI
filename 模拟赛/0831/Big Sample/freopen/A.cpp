#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define uke "Genshin Impact, Qi Dong!"

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, m; i64 res;
struct Edge
{
	int u, v, w;
	friend bool operator < (const Edge& _x, const Edge& _y)
	{ return _x.w < _y.w; }
} e[M << 1];

namespace DSU
{
int fa[N];
inline void init(int n) { for (int i = 1; i <= n; ++i) fa[i] = i; }
inline int  find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[y] = x; }
}
using namespace DSU;

int main()
{
	freopen("freopen.in", "r", stdin);
	freopen("freopen.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	if (m < n) { cout << uke << endl; exit(0); }
	for (int i = 1, l, r, c; i <= m; ++i)
	{
		cin >> l >> r >> c;
		e[i] = { l - 1, r, c };
	}

	init(n);
	sort(e + 1, e + m + 1);

	int k = 0;
	for (int i = 1; i <= m && k <= n; ++i)
	{
		int x = find(e[i].u);
		int y = find(e[i].v);
		if (x != y) merge(x, y), ++k, res += e[i].w;
	}

	if (k < n) { cout << uke << endl; exit(0); }

	cout << res << endl;
	return 0;
}