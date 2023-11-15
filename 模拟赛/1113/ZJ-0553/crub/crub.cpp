#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int a, b, c;
char ch[500][500];

inline void solve()
{
	cin >> a >> b >> c;

	int la = 2 * a + 1;
	int lb = 2 * b + 1;
	int lc = 2 * c + 1;

	// a →
	// b ↑
	// c ↓

	rep (i, 1, lc + 2 * b) rep (j, 1, la + 2 * b) ch[i][j] = '.';

	// set lines

	// set top surface
	rep (i, 1, 2 * b)
	{
		if (i & 1) { rep (j, 1, la) ch[i][(2 * b - i + 1) + j] = (j & 1) ? '+' : '-'; }
		else { rep (j, 1, la) if (j & 1) ch[i][(2 * b - i + 1) + j] = '/'; }
	}

	// set front surface
	rep (i, 1, lc)
	{
		if (i & 1) { rep (j, 1, la) ch[i + (2 * b)][j] = (j & 1) ? '+' : '-'; }
		else { rep (j, 1, la) if (j & 1) ch[i + (2 * b)][j] = '|'; }
	}

	// set right surface
	rep (i, 1, 2 * b)
	{
		if (i & 1) { rep (j, 1, 2 * c) if (!(j & 1)) ch[2 * b - i + 1 + j][la + i] = '/'; }
		else { rep (j, 1, 2 * c) ch[2 * b - i + 1 + j][la + i] = (j & 1) ? '|' : '+'; }
	}

	// print
	rep (i, 1, lc + 2 * b)
	{
		rep (j, 1, la + 2 * b) cout << ch[i][j];
		cout << endl;
	}
}

int main()
{
	file("crub");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}