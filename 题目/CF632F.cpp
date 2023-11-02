#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define YESRES cout << "MAGIC" << endl;
#define NORES cout << "NOT MAGIC" << endl;
#define sqr(x) ((x) * (x))
#define index(x, y) ((x - 1) * n + y)

using namespace std;

const int R = 2510;
const int N = 7e6 + 10;

int n, a[R][R];

struct Node
{
	int u, v, w;
	friend bool operator < (const Node& x, const Node& y)
		{ return x.w < y.w; }
} P[N];

namespace DSU
{
int fa[N];
inline void init(int n)
	{ rep (i, 0, n + 5) fa[i] = i; }
inline int find(int x)
	{ return fa[x] == x ? x : fa[x] = find(fa[x]); }
} using namespace DSU;

inline void Kruskal()
{
	sort(P + 1, P + sqr(n) + 1);
	P[sqr(n) + 1].w = -1; init(n);
	for (int l = 1, r = 0; l <= sqr(n); l = r + 1)
	{
		while (P[r + 1].w == P[l].w) ++r;
		if (P[l].w)
		{
			rep (i, l, r)
			{
				if (find(P[i].u) == find(P[i].v))
					{ NORES; return; }
			}
		}
		rep (i, l, r)
			fa[find(P[i].u)] = find(P[i].v);
	}
	YESRES; return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 1, n) rep (j, 1, n)
		a[i][j] = -1;

	rep (i, 1, n) rep (j, 1, n)
	{
		cin >> a[i][j];
		P[index(i, j)] = { i, j, a[i][j] };
		if (~a[j][i] && a[i][j] != a[j][i]) { NORES; exit(0); }
		if (i == j && a[i][i] != 0) { NORES; exit(0); }
	}

	Kruskal();

	return 0;
}