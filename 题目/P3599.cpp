#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

namespace MillerRabin
{
inline i64 fpow(i64 a, i64 k, const i64 P)
{
	i64 res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * a % P;
		a = a * a % P;
	}
	return res;
}
inline bool isprime(i64 n)
{
	if (n < 3) return n == 2;
	if ((n & 1) == 0)  return false;
	static const i64 A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
	i64 t = n - 1, h = 0;
	h = __builtin_ctz(t); t >>= h;
	for (i64 a : A)
	{
		a %= n; if (a <= 1) continue;
		i64 v = fpow(a, t, n);
		if (v == 1 || v == n - 1) continue;
		for (int i = 1; i <= h; ++i)
		{
			v = v * v % n;
			if (v == n - 1 && i != h) { v = 1; break; }
			if (v == 1) return false;
		}
		if (v != 1) return false;
	}
	return true;
}
} using namespace MillerRabin;

const int N = 1e5 + 10;

int n, inv[N];

inline void solve1()
{
	cin >> n;
	if (n == 1) { cout << 2 << endl << 1 << endl; return; }
	if (n & 1) { cout << 0 << endl; return; }

	cout << 2 << endl;
	rep (i, 0, n - 1)
		cout << (i & 1 ? i : n - i) << ' ';
}

inline void solve2()
{
	cin >> n;
	if (n == 1) { cout << "2\n1" << endl; return; }
	if (n == 4) { cout << "2\n1 3 2 4" << endl; return; }
	if (!isprime(n)) { cout << 0 << endl; return; }

	cout << "2\n1 ";
	inv[1] = 1;
	rep (i, 2, n - 1)
	{
		inv[i] = 1ll * (n - n / i) * inv[n % i] % n;
		cout << 1ll * i * inv[i - 1] % n << ' ';
	}
	cout << n << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int X, T; cin >> X >> T;
	if (X == 1) while (T--) solve1();
	if (X == 2) while (T--) solve2();
	return 0;
}