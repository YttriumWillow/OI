#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e6 + 10;

int n, m, a[N];
bool d[N];
struct Node
{
	int v, id;
	friend bool operator < (const Node& A, const Node& B) { return A.v > B.v; }
};
__gnu_pbds::priority_queue<Node> q[N];

namespace DSU
{
int fa[N];
inline void init(int n) { rep (i, 1, n + 2) fa[i] = i; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[y] = x; } // set(x) <- set(y)
}

int main()
{
	cin >> n;

	DSU::init(n);

	rep (i, 1, n)
	{
		cin >> a[i];
		q[i].push({ a[i], i });
	}

	cin >> m;

	while (m--)
	{
		char opt; int x, y;
		cin >> opt;
		if (opt == 'M')
		{
			cin >> x >> y;
			if (d[x] or d[y]) continue;
			x = DSU::find(x); y = DSU::find(y);
			if (x == y) continue;

			if (q[x].size() < q[y].size()) swap(x, y);
			q[x].join(q[y]); DSU::fa[y] = x;
		}
		if (opt == 'K')
		{
			cin >> x;
			if (d[x]) { cout << 0 << endl; continue; }
			x = DSU::find(x);

			Node res = q[x].top(); q[x].pop();

			cout << res.v << endl; d[res.id] = 1;
		}
	}

	return 0;
}