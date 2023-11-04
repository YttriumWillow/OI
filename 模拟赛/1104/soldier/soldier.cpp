#include <bits/stdc++.h>

#define i64 long long 
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 8010;

int n, m, k[N];
ull res, st[N];

inline bool check(int x, int y)
{
	int cnt = 0;
	ull stx = st[x], sty = st[y];
	rep (i, 1, m)
	{
		if ((sty >> (i - 1)) & 1ull)
		{
			ull f = stx & ((1ull << i) - 1ull);
			if (__builtin_popcountll(f)) ++cnt;
			stx -= f;
		}
	}
	return cnt & 1;
}

signed main()
{
	file("soldier");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n)
	{
		int x, k; cin >> k;
		while (k--) { cin >> x; st[i] |= (1ull << (x - 1)); }
	}

	rep (i, 1, n) rep(j, i + 1, n)
		if (check(i, j)) ++res;
	
	cout << res << endl;

	return 0;
}