#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int n, k; i64 res;

int main()
{
	file("card");

	cin >> n >> k;

	rep (i, 1, n)
	{
		i64 x, y; cin >> x >> y;
		res += max(0ll, x);
	}

	cout << res << endl;
	return 0;
}