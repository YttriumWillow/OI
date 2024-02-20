#include <iostream>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;
const i64 mod = 998244353;

int n, q, a[N], P; // the delta distance of array's left pointer
i64 tot, cnt, res[N], ans;
bool rev;

namespace BIT
{
#define lowbit(x) ((x) & (-x))
int t[N];
inline void add(int x, int v)
{
	for (int i = x; i <= n + 3; i += lowbit(i))
		t[i] += v;
}
inline int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += t[i];
	return res;
}
} using namespace BIT;

signed main()
{
	// oh i found that nxd is a shortage of both nixudui & Naxida(Nahida).
	
	file("river");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q; tot = n * (n - 1) / 2;
	rep (i, 1, n)
	{
		cin >> a[i];
		add(a[i], 1);
		cnt += i - query(a[i]);
	}

	// cerr << "init: " << cnt << endl;

	rep (i, 1, q)
	{
		char opt; cin >> opt;

		if (opt == '0')
		{
			int lpos = (P % n + n) % n + 1;
			int rpos = (((lpos - 2) % n + n) % n + 1);

			// cerr << "P: " << P << endl;
			// cerr << "lpos: " << lpos << " rpos: " << rpos << endl;

			if (!rev)
			{
				cnt -= (a[lpos] - 1);
				cnt += (n - a[lpos]);
			}
			else
			{
				cnt += (a[rpos] - 1);
				cnt -= (n - a[rpos]);
			}
			
			rev ? --P : ++P;
			
		}
		else if (opt == '1') { rev ^= 1; }

		res[i] = rev ? tot - cnt : cnt;

		ans = ((1ll * ans * 233 % mod + 1ll * res[i] % mod) % mod + mod) % mod;
	}

	cout << ans << endl;

	return 0;
}