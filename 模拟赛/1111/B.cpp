#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;

int n, m;
unsigned int p, a[N], b[N], c[N];

namespace BIT
{
int t[N];
#define lowbit(x) ((x) & (-x))
inline void add(int x, int v)
{
	for (int i = x; i <= n + 2; i += lowbit(i))
		t[i] += v;
}
inline int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += t[i];
	return res;
}
inline void clear() { fill(t, t + n + 5, 0); }
}

int main()
{
	// file("xor");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];

	while (m--)
	{
		cin >> p;
		rep (i, 1, n) b[i] = c[i] = a[i] ^ p;
		sort(c + 1, c + n + 1);
		int len = unique(c + 1, c + n + 1) - c - 1;

		rep (i, 1, n) b[i] = lower_bound(c + 1, c + len + 1, b[i]) - c;

		i64 res = 0;

		rep (i, 1, n)
		{
			BIT::add(b[i], 1);
			res += i - BIT::query(b[i]);
		}

		cout << res << endl;

		BIT::clear();
	}
	return 0;
}