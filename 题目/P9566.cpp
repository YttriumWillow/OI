#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define NaN "Impossible"

using namespace std;

const int N = 1e6 + 10;

int n, m, cnt;
bool flg, f[N];
char a[N], sve[N];

inline bool check(char st, char ed)
{
	a[1] = st, a[n] = ed; cnt = 0; flg = 1;

	rep (i, 1, n) if (f[i]) a[i] = '0';
	rep (i, 2, n) if (a[i] != a[i - 1]) ++cnt;


	if ((cnt & 1) ^ (m & 1)) { return 0; }


	if (cnt > m)
	{
		int l = 1, r = n;
		per (i, n - 1, 1)
		{
			if (cnt == m) break;

			if (flg && f[i]) { flg = 0; r = i; }

			if (!flg && !f[i])
			{
				flg = 1; l = i + 1;

				if (a[r + 1] == '1' && a[l - 1] == '1')
				{
					cnt -= 2;
					rep (i, l, r) a[i] = '1';
				}
			}
		}
	}
	else
	{
		per (i, n - 1, 2)
		{
			if (cnt == m) break;

			if (f[i])
			{
				if (a[i + 1] == a[i] && a[i - 1] == a[i])
				{
					a[i] = '1';
					cnt += 2;
				}
			}
		}
	}

	return cnt == m;
}

inline void solve()
{
	cin >> n >> m;
	cin >> (sve + 1);


	rep (i, 1, n) f[i] = (sve[i] == '?');

	f[1] = f[n] = 0;

	bool fl = (a[1] == '?');
	bool fr = (a[n] == '?');

	if (fl && fr)
	{
		rep (i, 1, n) a[i] = sve[i];
		if (check('0', '0'))
		{ cout << a + 1 << endl; return; }

		rep (i, 1, n) a[i] = sve[i];
		if (check('0', '1'))
		{ cout << a + 1 << endl; return; }

		rep (i, 1, n) a[i] = sve[i];
		if (check('1', '0'))
		{ cout << a + 1 << endl; return; }

		rep (i, 1, n) a[i] = sve[i];
		if (check('1', '1'))
		{ cout << a + 1 << endl; return; }

		cout << NaN << endl; return;
	}

	if (fl)
	{
		rep (i, 1, n) a[i] = sve[i];
		if (check('0', a[n]))
		{ cout << a + 1 << endl; return; }

		rep (i, 1, n) a[i] = sve[i];
		if (check('1', a[n]))
		{ cout << a + 1 << endl; return; }

		cout << NaN << endl; return;
	}

	if (fr)
	{
		rep (i, 1, n) a[i] = sve[i];
		if (check(a[1], '0'))
		{ cout << a + 1 << endl; return; }

		rep (i, 1, n) a[i] = sve[i];
		if (check(a[1], '1'))
		{ cout << a + 1 << endl; return; }

		cout << NaN << endl; return;
	}

	rep (i, 1, n) a[i] = sve[i];
	if (check(a[1], a[n]))
		cout << a + 1 << endl;
	else
		cout << NaN << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}