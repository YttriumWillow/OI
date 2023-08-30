#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

i64 n, a[N];

template <typename Tp>
struct XorLinearBasis
{
#define LOG 62
	Tp p[LOG] = { 0 }; bool full = 0;
	inline void insert(Tp x)
	{
		for (int i = LOG; ~i; --i)
			if (x >> i & 1)
			{
				if (!p[i]) { p[i] = x; return; }
				x ^= p[i];
			}
		full = 1;
	}
	inline bool exist(Tp x)
	{
		for (int i = LOG; ~i; --i)
			if (x >> i & 1)
			{
				if (!p[i]) { return 0; }
				x ^= p[i];
			}
		return 1;
	}
	inline Tp max()
	{
		Tp res = 0;
		for (int i = LOG; ~i; --i)
			res = std::max(res, res ^ p[i]);
		return res;
	}
	inline Tp min()
	{
		if (full) return 0;
		for (int i = 0; i <= LOG; ++i)
			if (p[i]) return p[i];
	}
	inline Tp query(int k)
	{
		Tp res = 0;
		int tot = 0;
		static Tp tmp[LOG];
		k -= full;
		if (!k) return 0;

		for (int i = 0; i <= LOG; ++i)
		{
			for (int j = i - 1; ~j; --j)
				if (p[i] >> j & 1)
					a[i] ^= a[j];
			if (a[i]) tmp[tot++] = a[i];
		}
		if (k >= (1ll << tot)) return -1;
		for (int i = 0; i < tot; ++i)
			if (k >> i & 1)
				res ^= tmp[i];
		return res;
	}
};

XorLinearBasis<i64> xlb; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], xlb.insert(a[i]);
	cout << xlb.max() << endl;

	return 0;
}