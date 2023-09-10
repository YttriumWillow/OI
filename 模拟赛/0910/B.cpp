#include <iostream>

#define int long long
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;

int n, sum[2], a[N];
bool flg;

inline int prev(int pos) { return (pos - 1 + n) % n; }
inline int next(int pos) { return (pos + 1) % n; }

inline void solve()
{
	cin >> n;
	
	flg = 1; 
	sum[0] = sum[1] = 0;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum[i & 1] += a[i];
	}
	
	// judge
	if ((sum[0] + sum[1]) & 1) { cout << 0 << endl; return; }
	if (!(n & 1) && sum[0] != sum[1]) { cout << 0 << endl; return; }
	
	for (int i = 0; i < n; ++i)
	{
		if (a[prev(i)] + a[next(i)] == a[i])
			a[prev(i)] = a[next(i)] = a[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[prev(i)] + a[next(i)] < a[i])
			flg = 0;
	}
	cout << flg << endl;
}

signed main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}