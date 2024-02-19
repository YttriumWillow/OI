#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~")
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, r, l) for(int i = (r); i >= (l); --i)

using namespace std;

const int N = 2e5 + 10;

i64 n, mod, a[N], res[N];
char p[N];

void solve()
{
	cin >> n >> mod;

	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n) cin >> p[i];

	int l = 1, r = n;

	rep (i, 1, n - 1)
		(p[i] == 'L') ? ++l : --r;

	// cerr << "l/r : " << l << ' ' << r << endl;

	res[n] = a[l] % mod;
	int prv = a[l];

	per (i, n - 1, 1)
	{
		int pos = (p[i] == 'L') ? --l : ++r;
		res[i] = prv * a[pos] % mod;
		prv = prv * a[pos] % mod;
	}

	rep (i, 1, n)
		cout << res[i] << " \n"[i == n];

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}
