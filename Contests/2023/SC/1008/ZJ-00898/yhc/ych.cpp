// D

#include <iostream>
#include <cstring>
#include <ext/rope>

#define i64 long long
#define u64 unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;
using namespace __gnu_cxx;

const int N = 3e3 + 10;
const u64 B = 37;

int n, q;
int l1, r1, l2, r2;
i64 res; string s;

namespace Sub1
{
crope F, R;
inline void solve()
{
	F.insert(0, s.c_str());
	reverse(s.begin(), s.end());
	R.insert(0, s.c_str());

	while (q--)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		res = 0;
		crope x = F.substr(l2, r2 - l2 + 1);

		for (int i = l1; i <= r1 + 1; ++i)
			for (int j = i; j <= r1 + 1; ++j)
				if (x == F.substr(j, r1 - j + 1) + R.substr(n + 1 - j, j - i) + F.substr(l1, i - l1))
					++res;

		cout << res << endl;
	}
}
}

#define sub(l, r) s.substr(l, r - l + 1)

namespace Sub2
{
u64 h1, h2, pw[N];
u64 pre[N][N], suf[N][N];
inline void solve()
{
	pw[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
			pre[i][j] = pre[i][j - 1] * B + (s[i] - 'a');
		for (int j = n; j >= i; --j)
			suf[i][j] = suf[i][j + 1] * B + (s[i] - 'a');
		pw[i] = pw[i - 1] * B;
	}
	while (q--)
	{
		cin >> l1 >> r1 >> l2 >> r2;

		res = 0; h2 = pre[l2][r2];

		// cout << "t: " << sub(l2, r2) << endl;

		for (int i = l1; i <= r1 + 1; ++i)
			for (int j = i; j <= r1 + 1; ++j)
			{
				// u = [l1, i - 1]
				// v = [i,  j - 1]
				// w = [j,  r1]
				h1 = pre[j][r1] + (suf[i][j - 1]) * pw[r1 - j + 1] + (pre[l1][i - 1]) * pw[r1 - i + 1];
				if (h1 == h2)
				{
					// cout << "f: " << (sub(j, r1) + sub(i, j - 1) + sub(l1, i - 1)) << endl;
					++res;
				}
			}
		cout << res << endl;
	}
}
}

int main()
{
	file("ych");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	cin >> s; s = '#' + s;

	if (n <= 100 && q <= 100) Sub1::solve(), exit(0);

	Sub2::solve();
	return 0;
}