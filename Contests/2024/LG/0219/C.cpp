#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e5 + 10;

int n, m;

namespace DSU
{
int fa[N];
void clear() { rep (i, 1, n + 5) fa[i] = i; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }
} using namespace DSU;

void solve()
{
	cin >> n >> m; clear();

	rep (i, 1, m)
	{
		int u, v; cin >> u >> v;
		merge(u, v);
	}

	int tot = 0, r[2];
	rep (i, 1, n) if (find(i) == i)
	{
		if (tot < 2) r[tot] = i;
		++tot;
	}

	if (tot == 1 and n > 1) { cout << "No" << endl; return; }

	cout << "Yes" << endl;

	cout << r[0] << ' ' << r[1] << endl;

	rep (i, 1, n)
	{
		if (i == r[0] or i == r[1]) continue;
		if (find(i) == r[0]) cout << i << ' ' << r[1] << endl;
		else cout << i << ' ' << r[0] << endl;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) { solve(); }

	return 0;
}