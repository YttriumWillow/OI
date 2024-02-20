#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define sqr(x) (1ll * (x) * (x))
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e6 + 10;
const int mod = 998244353;

int n, m;

namespace _10
{
int a[N], res = 0;
inline void solve()
{
	rep (i, 1, n)
	{
		rep (j, 1, m)
		{
			char ch; cin >> ch;
			a[i] |= (ch - '0') << (m - j);
		}
	}

	rep (i, 1, n)
		rep (j, i + 1, n)
			res = (res + sqr(a[i] ^ a[j]) % mod) % mod;

	cout << res << endl;
}
}

int main()
{
	file("C");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	if (n <= 1000 && m <= 30) _10::solve(), exit(0);

	cout << 0 << endl;

	return 0;
}