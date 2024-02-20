#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~")
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)

using namespace std;

const int N = 55;

int n;
char a[N];
int f[N];

inline void solve()
{
	cin >> n;
	rep (i, 1, n) cin >> a[i];

	int ans = a[1] == '@';
	rep (i, 2, n)
	{
		if (a[i - 1] == '*' and a[i - 2] == '*')
			{ break; }
		else if (a[i] == '@')
			ans += 1;
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}