#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

constexpr int ST = 1145;

int n, p[ST];
i64 v, res;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		cin >> v; int t = 0;
		while (v) { t |= 1 << (v % 10); v /= 10; }
		++p[t];
	}

	rep (i, 0, (1 << 10) - 1)
		rep (j, i + 1, (1 << 10) - 1)
			if (i & j) res += 1ll * p[i] * p[j];

	rep (i, 0, (1 << 10) - 1)
		res += 1ll * p[i] * (p[i] - 1) / 2;

	cout << res << endl;
	return 0;
}