// C

#include <iostream>

#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e7 + 10;

int n, m, a[N]; i64 res;
int cnt;

inline void solve()
{
	cin >> n >> m; // cnt += n;
	i64 t = 1; res = 0;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] < t)
		{
			if (a[i + 1] - a[i] > 1)
				++a[i], ++res;
			else --t;
		}
		else if (a[i] > t)
			res += (a[i] - t);
		++t;
	}
	cout << res << endl;
}

int main()
{
	file("flower");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	
	// cerr << cnt << endl;	
	return 0;
}