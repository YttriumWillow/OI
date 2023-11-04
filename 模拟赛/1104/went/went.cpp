#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e6 + 10;

int n, a[N], cnt[2], res[2];

int main()
{
	file("went");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		char ch; cin >> ch;
		a[i] = ch - '0';
	}

	++cnt[a[1]];
	rep (i, 2, n)
	{
		if (a[i] == a[i - 1]) cnt[0] ? ++cnt[0] : ++cnt[1];
		else
		{
			if (cnt[0]) { res[0] += cnt[0] - 1; cnt[0] = 0; ++cnt[1]; }
			else 		{ res[1] += cnt[1] - 1; cnt[1] = 0; ++cnt[0]; }
		}
	}

	if (cnt[0]) res[0] += cnt[0] - 1;
	if (cnt[1]) res[1] += cnt[1] - 1;

	cout << max(res[0], res[1]) + 1 << endl;

	return 0;
}