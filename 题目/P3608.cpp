#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

struct BIT
{
int t[N], siz, len;
#define lowbit(x) ((x) & (-x))
inline void init(int n) { len = n; siz = 0; }
inline void add(int x, int v)
{
	for (int i = x; i <= len + 5; i += lowbit(i))
		t[i] += v;
	siz += v;
}
inline int sum(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += t[i];
	return res;
}
inline int query(int x) { return siz - sum(x); }
};

int n, m, res;
int h[N], g[N];
BIT tl, tr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> h[i], g[i] = h[i];

	sort(g + 1, g + n + 1);
	int len = unique(g + 1, g + n + 1) - g - 1;
	for (int i = 1; i <= n; ++i)
		h[i] = lower_bound(g + 1, g + len + 1, h[i]) - g;

	tl.init(len + 1); tr.init(len + 1);

	for (int i = 1; i <= n; ++i)
		tr.add(h[i], 1);

	for (int i = 1; i <= n; ++i)
	{
		int suml = tl.query(h[i]);
		int sumr = tr.query(h[i]);

		if (suml < sumr) swap(suml, sumr);
		if (suml > (sumr << 1)) ++res;

		tl.add(h[i], 1);
		tr.add(h[i], -1);
	}

	cout << res << endl;
	return 0;
}