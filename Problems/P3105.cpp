#include <iostream>
#include <algorithm>
#include <map>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int n, res, sum[N];
pair<int, int> P[N];
map<int, int> prv;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		int x; char col;
		cin >> x >> col;
		P[i] = { x, (col == 'W' ? 1 : -1) };
	}
	sort(P + 1, P + n + 1);

	prv[0] = 0;

	rep (i, 1, n)
	{
		sum[i] = sum[i - 1] + P[i].second;
		if (!prv[sum[i]] && sum[i] < 0)
			prv[sum[i]] = i;
		else if (sum[i] < 0)
			res = max(res, P[i].first - P[ prv[sum[i]] + 1 ].first);

		if (sum[i] >= 0)
			res = max(res, P[i].first - P[1 + (sum[i] & 1)].first);
	}

	cout << res << endl;
	return 0;
}