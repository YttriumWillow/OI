#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

i64 a, b, c;
i64 cnt, P[210];
i64 res;

inline void solve()
{
	cin >> a >> b >> c; res = 0;

	// found out more easy to type 'and' than '&&' QAQ
	// Na2S2O3's say is right.
	if (a == 1 and b == 1 and c == 1) { cout << -1 << endl; return; }
	if (a > b or b > c) { cout << (b == c) << endl; return; }
	if (a == b and b != c) { cout << 0 << endl; return;  }
	if (a == 1 and b == 1) { cout << 0 << endl; return; }

	if (a) // 为什么下面搞不出来。 c = b ^ k, b = a ^ k. 这种 tm 特判就过了。
	{
		i64 t = c;
		while (!(t % b)) t /= b;
		res += (t == 1);
	}

	cnt = 0;
	while (c) P[++cnt] = c % b, c /= b;

	i64 v = 0, B = 1;
	rep (i, 1, cnt)
	{
		v += B * P[i];
		B = B * a;
	}
	res += (v == b);
	cout << res << endl;

}

int main()
{
	file("poly");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}