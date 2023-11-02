#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e6 + 10;

int n, a[N], b[N];
int x, y;

inline void move()
{
	i64 suma = 0, sumb = 0;
	rep (i, 1, n)
	{
		suma += a[i];
		if (suma > sumb)
		{
			cout << 0 << endl;
			return;
		}
		sumb += b[i];
	}
	cout << n + 1 << endl;
}

inline void solve()
{
	cin >> n;
	a[0] = b[0] = a[n + 1] = b[n + 1];

	rep (i, 1, n)
		cin >> a[i] >> b[i];

	x = 0; y = 1; move();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}