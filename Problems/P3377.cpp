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

struct Node
{
	int v, id;
	friend bool	operator < (const Node& X, const Node& Y)
	{ return (X.v ^ Y.v) ? (X.v > Y.v) : (X.id > Y.id); }
};
__gnu_pbds::priority_queue<Node> q[N];

namespace DSU
{
int fa[N];
inline void init(int n) { rep (i, 1, n + 2) fa[i] = i; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[x] = y; }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; DSU::init(n);
	rep (i, 1, n)
	{
		cin >> a[i];
		q[i].push({ a[i], i });
	}

	while (m--)
	{
		int opt, x, y; cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y;
			if (del[x] or del[y]) continue;
			x = DSU::find(x); y = DSU::find(y);
			if (x == y) continue;
			if (q[x].size() > q[y].size()) swap(x, y);
			q[y].join(q[x]); DSU::merge(x, y);
		}
		else if (opt == 2)
		{
			cin >> x;
			if (del[x]) { cout << -1 << endl; continue; }
			x = DSU::find(x); Node res = q[x].top();
			cout << res.v << endl; del[res.id] = 1;
			q[x].pop();
		}
	}

	return 0;
}