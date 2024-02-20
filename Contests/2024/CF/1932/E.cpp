#include <iostream>
#include <algorithm>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~")
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, r, l) for(int i = (r); i >= (l); --i)

using namespace std;

const int N = 4e5 + 10;
const int L = 4e5 + 100;

int n, a[N], prv[N];
int res[L];

void solve()
{
	cin >> n;

	rep (i, 1, n)
	{
		char ch; cin >> ch;
		a[i] = ch - '0';
		prv[i] = prv[i - 1] + a[i]; 
	}

	reverse(prv + 1, prv + n + 1);

	// rep (i, 1, n)
	// 	cout << prv[i] << " \n"[i == n];

	memset(res, 0, sizeof(res));

	int d = 0;

	rep (i, 1, n)
	{
		int t = prv[i], cnt = 0;
		while (t)
		{
			res[i + cnt] += t % 10;
			d = max(d, i + cnt);
			if (res[i + cnt] > 9)
			{
				d = max(d, i + cnt + 1);
				res[i + cnt + 1] += res[i + cnt] / 10;
				res[i + cnt] %= 10;
			}
			++cnt;
			t /= 10;
		}
	}

	// cout << d << endl;
	per (i, d, 1)
		cout << res[i];
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
