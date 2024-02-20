#include <bits/stdc++.h>

#define int long long 
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Order pair<int, int>
#define date first
#define req second

using namespace std;

const int N = 110;

Order a[N];
int n, k;
int sto, inc;

inline void solve()
{
	sto = inc = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].date >> a[i].req;

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i)
	{
		inc = (a[i].date - a[i - 1].date) * k;
		sto += inc;
		if (sto < a[i].req) { cout << "No" << endl; return; }
		sto -= a[i].req;
	}

	cout << "Yes" << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}
