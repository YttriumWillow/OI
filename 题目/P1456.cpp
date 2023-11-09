#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int n, m, a[N];
bool del[N];

__gnu_pbds::priority_queue<int> q[N];

namespace DSU
{
int fa[N];
inline void init(int n) { rep (i, 1, n + 2) fa[i] = i; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[y] = x; }
}

inline void solve()
{
	DSU::init(n);

	rep (i, 1, n)
	{
		cin >> a[i];
		q[i].clear();
		q[i].push(a[i]);
	}

	cin >> m;

	while (m--)
	{
		int x, y; cin >> x >> y;
		x = DSU::find(x); y = DSU::find(y);
		if (x == y) { cout << -1 << endl; continue; }

		int X = q[x].top(); q[x].pop();
		int Y = q[y].top(); q[y].pop();

		q[x].push(X / 2);
		q[x].push(Y / 2);

		if (q[x].size() < q[y].size()) swap(x, y);
		q[x].join(q[y]); DSU::merge(x, y);

		cout << q[x].top() << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n) solve();

	return 0;
}