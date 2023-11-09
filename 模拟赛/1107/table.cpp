#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 15;
const int mod = 12;

int a[N], b[N]; bool v[N];
int now = 0, cnt = 0;

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	rep (i, 0, 11) a[i] = i;

	do
	{
		cnt = 0;
		rep (i, 0, 11)
		{
			rep (j, 0, 6) b[j] = a[(i + j) % mod];
			sort(b, b + 7);
			if (
			    b[1] == (b[0] + 2) % mod and
			    b[2] == (b[0] + 4) % mod and
			    b[3] == (b[0] + 5) % mod and
			    b[4] == (b[0] + 7) % mod and
			    b[5] == (b[0] + 9) % mod and
			    b[6] == (b[0] + 11) % mod
			) ++cnt;
		}

		if (cnt == 12) cout << "!!!!!" << endl;
		if (cnt > now)
		{
			cout << "cnt: " << (now = cnt) << endl;
			rep (i, 0, 11)
				cout << a[i] << " \n"[i == 11];
		}
		if (!v[a[0]]) { v[a[0]] = 1; cout << a[0] << endl; }
	}
	while (next_permutation(a, a + 12));

	

	return 0;
}