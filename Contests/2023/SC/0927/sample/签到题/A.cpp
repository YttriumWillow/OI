#include <iostream>

#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 2e6 + 10;

int n, buc[N];
int bef, cnt, kd;
bool res, f1, f2;

inline void solve()
{
	cin >> n;

	res = 0, cnt = 0, bef = 0;
	fill(buc + 1, buc + n + 1, 0);

	for (int i = 1, k, x; i <= n; ++i)
	{
		cin >> k;

		if (k == 0) continue;
		if (k == 1) { int t; cin >> t; continue; }

		bef = cnt; f1 = 0; f2 = 0; kd = 0;

		for (int j = 1; j <= k; ++j)
		{
			cin >> x;
			if (!buc[x]) { ++cnt; f1 = 1; }
			else 		 { ++kd; }
			++buc[x];
		}

		// if (k <= 1) continue;

		if (kd < bef) f2 = 1;

		if (f1 && f2) res = 1;
	}
	
	cout << (res ? "YES" : "NO") << endl;
}

int main()
{
	file("sign");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}