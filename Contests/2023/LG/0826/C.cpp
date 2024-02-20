#include <bits/stdc++.h>

#define int long long

#define x first
#define v second

using namespace std;

const int N = 5e5 + 10;

int n, _, r, a[N], b[N], z, y, o;
map<int, int> d;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		_ = max({ a[i], b[i], _ });
		if (a[i] > b[i]) { --d[a[i]], ++d[b[i]]; }
	}

	r = _;
	for (auto p : d)
	{
		z += p.v;
		if (!z) { r += (p.x - y) * 2; y = 0; }
		if (!y && z) { y = p.x; }
	}
	r = min(r, _ * 2 - (*d.begin()).x);
	for (auto p : d)
	{
		z += p.v;
		if (!z) { o += (p.x - y) * 2; y = 0; }
		if (!y && z) { r = min(2 * _ + o - p.x, r); y = p.x; }
	}

	cout << r;
	return 0;
}