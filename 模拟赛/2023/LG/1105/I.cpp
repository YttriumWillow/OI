#include <iostream>
#include <iomanip>
#include <cmath>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const double Pi = acos(-1);

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	double part = 2, ans = 0, res = 0, sum = 1;
	rep (i, 1, m - 1)
	part += (2.0 * m > Pi * i) ? Pi * 2.0 * i / m : 4;
	rep (i, 1, n)
	{
		ans += part * i * m + 2 * m * (res + sum);
		res += part * i + sum;
		sum += 2 * m;
	}
	if (m == 1) ans -= (1 + n) * n * m;
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}