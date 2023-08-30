#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

i64 n, res;

struct Mineral
{
	i64 x, y;
	friend bool operator < (const Mineral& _x, const Mineral& _y)
	{ return _x.y > _y.y; }
} a[N];

template <typename Tp>
struct XorLinearBasis
{
#define LOG 62
	Tp p[LOG] = { 0 }; bool full = 0;
	inline bool insert(Tp x)
	{
		for (int i = LOG; ~i; --i)
			if (x >> i & 1)
			{
				if (!p[i]) { p[i] = x; return 1; }
				x ^= p[i];
			}
		return 0;
	}
};
XorLinearBasis<i64> xlb; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		if (xlb.insert(a[i].x))
			res += a[i].y;
	cout << res << endl;
	return 0;
}