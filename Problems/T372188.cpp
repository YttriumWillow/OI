#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

namespace DSU
{
int fa[N];
inline void init(int n) { for (int i = 1; i <= n + 5; ++i) fa[i] = i; }
inline void find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[y] = x; }
}

struct Edge
{
	int u, v, w;
	friend bool operator < (const Edge& a, const Edge& b) const
	{ return a.w < b.w; }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, l, r, c; i <= m; ++i)
	{
		cin >> l >> r >> c;
		add(l - 1, r, c);
	}

	sort(a + 1, a + m + 1); init(m);

	for (int i = 1; i <= m; ++i)
	{

	}
	return 0;
}