#include <iostream>
#include <climits>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n, d;
i64 k[6], res;
i64 pos[1000010][6];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> d;
	rep (i, 1, n) rep (j, 1, d)
	cin >> pos[i][j];

	rep (S, 0, (1 << (d - 1)) - 1)
	{
		i64 Max = LLONG_MIN, Min = LLONG_MAX;
		rep (i, 1, d) k[i] = (S & (1 << (i - 1))) ? 1 : 0;
		rep (i, 1, n)
		{
			i64 sum = 0;
			rep (j, 1, d) sum += pos[i][j] * (1 - k[j] * 2);
			Max = max(Max, sum); Min = min(Min, sum);
		}
		res = max(res, Max - Min);
	}

	cout << res << endl;

	return 0;
}