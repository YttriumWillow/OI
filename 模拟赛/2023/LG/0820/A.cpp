#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5;

int n, p;

bool vis[N];

inline void spc()
{
	int mid = p >> 1;
	for (int i = 1; i <= min(n, mid); ++i)
		if (p - i <= n && i != p - i) cout << i << ' ' << p - i << ' ';
		else cout << i << ' ';
	cout << endl;
}

inline void solve()
{
	cin >> n >> p;
	
	/*fill(vis + 1, vis + n + 1, 0);*/

	if (p == 1) { for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n]; return; }
	if (n < p) { spc(); return; }

	int mid = p / 2;
	for (int i = 1; i <= mid - !(p % 2); ++i)
		for (int j = 1; j <= n / p + !!(n % p); ++j)
		{
			int l = (j - 1) * p + i;
			int r = j * p - i;
			if (l <= n/* && !vis[l]*/) { cout << l << ' '; /*vis[l] = 1;*/ }
			if (r <= n/* && !vis[r]*/) { cout << r << ' '; /*vis[r] = 1;*/ }
		}

	if (p % 2 == 0)
		for (int i = mid; i <= n; i += p)
			cout << i << ' ';
	
	for (int i = p; i <= n; i += p)
		cout << i << ' ';
		
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}

/*
9
9 1
5 2
1 12345
9 3
10 4
13 20
11 4
10 10
9 9

1 2 3 4 5 6 7 8 9
1 3 5 2 4
1
1 2 4 5 7 8 3 6 9
1 3 5 7 9 2 6 10 4 8
1 2 3 4 5 6 7 13 8 12 9 11 10
1 3 5 7 9 11 2 6 10 4 8
1 9 2 8 3 7 4 6 5 10
1 8 2 7 3 6 4 5 9
*/