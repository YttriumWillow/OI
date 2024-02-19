#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define int long long 
#define lowbit(x) ((x) & (-x))

using namespace std;

const int P = 1e5 + 10;
const int LG = 30;
const int Y = 1e7 + 10;

int m, q, p, x, y;
int a[21], b[21];
int f[P][LG];

inline int fpow(int v, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = (1ll * res * v) % p;
		v = (1ll * v * v) % p;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> q >> p;

	rep (i, 1, m)
		cin >> a[i] >> b[i];

	rep (i, 0, p - 1)
		rep (j, 1, m)
			f[i][0] = (f[i][0] + 1ll * a[j] * fpow(i, b[j]) % p) % p;

	for (int j = 1; (1 << j) <= Y; ++j)
		rep (i, 0, p - 1)
			f[i][j] = f[f[i][j - 1]][j - 1];

	rep (i, 1, q)
	{
		cin >> x >> y; x %= p;
		for (int k = 30; ~k; --k)
			if ((1 << k) & y) x = f[x][k];
		cout << x << endl;
	}
	return 0;
}