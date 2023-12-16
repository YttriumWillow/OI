#include <iostream>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);

using namespace std;

int n, k, res = -1;
string A, B;

int main()
{
	// file("master");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	cin >> A >> B;
	A = '#' + A;
	B = '#' + B;

	rep (i, 1, n) rep (j, 1, n)
	{
		int d = 0, cur = 0;
		while (i + d <= n and j + d <= n
		    and (A[i + d] == B[j + d] or cur < k) )
		{
			if (A[i + d] != B[j + d]) ++cur;
			++d;
		}
		if (d > res) res = d;
	}

	cout << res << endl;

	return 0;
}