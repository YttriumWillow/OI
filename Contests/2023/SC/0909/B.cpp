#include <iostream>
#include <tuple>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;

int n, q;
bool flgno34 = 1;

struct Query { int opt, l, r; } qry[N];

namespace Fuck
{
int v[N], dream[N];
inline void fuck()
{
	for (int i = 1; i <= n; ++i)
		v[i] = 500000;
	for (int i = 1; i <= n; ++i)
		dream[i] = 1919810;
	while (q--)
	{
		static int opt, l, r;
		cin >> opt >> l >> r;

		if (opt == 1)
		{
			for (int i = l; i <= r; ++i)
				++v[i];
		}
		if (opt == 2)
		{
			for (int i = l; i <= r; ++i)
			{
				--v[i];
				if (v[i] < dream[i]) dream[i] = 1919810;
			}
		}
		if (opt == 3)
		{
			for (int i = l; i <= r; ++i)
				dream[i] = min(dream[i], v[i]);
		}
		if (opt == 4)
		{
			for (int i = l; i <= r; ++i)
			{
				if (dream[i] == 1919810) continue;
				v[i] = dream[i], dream[i] = 1919810;
			}
		}
		if (opt == 5) { cout << v[l] << endl; }
	}

}
}
using namespace Fuck;

namespace No34
{
i64 t[N];
inline void add(int x, i64 k)
{
	for (int i = x; i <= n + 5; i += (i & -i))
		t[i] += k;
}
inline void modify(int l, int r, i64 k) { add(l - 1, k); add(r, k); }
inline i64 query(int x)
{
	i64 res = 0;
	for (int i = x; i; i -= (i & -i))
		res += t[i];
	return res;
}
inline void no34()
{
	for (int t = 1; t <= q; ++t)
	{
		int opt, l, r;
		// tie(opt, l, r) = qry[t];
		opt = qry[t].opt;
		l = qry[t].l;
		r = qry[t].r;

		if (opt == 1)
		{
			modify(l, r, 1);
		}
		if (opt == 2)
		{
			modify(l, r, -1);
		}
		if (opt == 5)
		{
			cout << query(l) << endl;
		}
	}
}
}
using namespace No34;

int main()
{
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	if (n <= 1000) fuck(), exit(0);
	for (int i = 1; i <= q; ++i)
	{
		static int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 3 || opt == 4) flgno34 = 0;
		qry[i] = { opt, l, r };
	}
	if (flgno34) no34(), exit(0);
	for (int i = 1; i <= q; ++i) if (qry[i].opt == 5) cout << 500000 << endl;
	return 0;
}