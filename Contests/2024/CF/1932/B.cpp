#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~")
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)

using namespace std;

const int N = 110;

int n, a[N];

void solve()
{
	cin >> n;

	rep (i, 1, n) cin >> a[i];

	i64 prv = 0;

	rep (i, 1, n)
	{
		prv = (prv / a[i] + 1) * a[i];
	}

	cout << prv << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}
