#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;
const i64 mod = 998244353;

int n, q, a[N];
i64 cnt;

namespace BIT
{
#define lowbit(x) ((x) & (-x))
int t[N];
inline void add(int x, int v)
{
	for (int i = x; i <= n + 3; i += lowbit(i))
		t[i] += v;
}
inline int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += t[i];
	return res;
}
} using namespace BIT;

int main()
{
	// file("river");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	rep (i, 1, n)
	{
		cin >> a[i];
		add(a[i], 1);
		cnt += i - query(a[i]);
	}

	cout << cnt << endl;

	return 0;
}
/*

9 8
9 7 2 5 6 8 1 4 3
01101100

*/