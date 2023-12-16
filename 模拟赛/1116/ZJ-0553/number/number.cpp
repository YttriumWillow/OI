#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)

using namespace std;

i64 n, cnt, f, res;
i64 cnt1, cnt0, cnt_, unc;

int main()
{
	file("number");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 1, n)
	{
		cin >> f;
		if (f == 1) res += (unc + cnt0 + cnt_ + cnt1), ++cnt1;
		else if (f > 0) res += (cnt1 + cnt_ + cnt0), ++unc;
		else if (f == 0) res += (cnt1 + unc), ++cnt0;
		else res += (cnt1 + unc), ++cnt_;
	}

	cout << res << endl;

	return 0;
}
// a_i * (a_j - 1) < a_j