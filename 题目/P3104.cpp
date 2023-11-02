#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 510;

int n, a[N], deg[N];
int cnt, res[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n + 1) cin >> a[i];

	rep (i, 1, n + 1)
	{
		int tot = 0;
		rep (j, 1, n + 1)
			if (j != i)
				deg[++tot] = a[j];

		bool flg = 1;

		rep (j, 1, n)
		{
			sort(deg + 1, deg + n + 1);
			for (int cur = n - 1; deg[cur] && deg[n]; --cur)
				--deg[n], --deg[cur];
			if (deg[n]) { flg = 0; break; }
		}
		if (flg) { res[++cnt] = i; }
	}

	cout << cnt << endl;
	rep (i, 1, cnt)
		cout << res[i] << endl;

	return 0;
}