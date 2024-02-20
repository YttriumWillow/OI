#include <iostream>
#include <cstring>

#define i64 long long
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const ull mod = 1e9 + 7;

ull n, a1, a2, x, y;

struct Mtx
{
	int r, c; ull m[5][5] = { 0 };

	inline void set() { rep (i, 1, min(r, c)) m[i][i] = 1; }

	Mtx() { memset(m, 0, sizeof m); }
	Mtx(int _r, int _c) { r = _r; c = _c; memset(m, 0, sizeof m); }

	ull* operator[](int x) { return m[x]; }

	friend Mtx operator * (Mtx& A, Mtx& B)
	{
		Mtx res(A.r, B.c);
		rep (i, 1, A.r) rep (j, 1, B.c) rep (k, 1, A.c)
			res[i][j] = (res[i][j] + A[i][k] * B[k][j] % mod) % mod;
		return res;
	}
	friend Mtx operator ^ (Mtx A, ull k)
	{
		Mtx res(A.r, A.c); res.set();
		for (; k; k >>= 1)
		{
			if (k & 1) res = res * A;
			A = A * A;
		}
		return res;
	}
};

inline void solve()
{
	cin >> n >> a1 >> a2 >> x >> y;
	a1 %= mod; a2 %= mod; x %= mod; y %= mod;
	if (n == 1) { cout << a1 * a1 % mod; return; }
	if (n == 2) { cout << (a1 * a1 % mod + a2 * a2 % mod) % mod << endl; return; }

	Mtx T(4, 4);
	T[1][1] = x * x % mod; T[1][2] = 1; T[1][3] = x; T[1][4] = x * x % mod;
	T[2][1] = y * y % mod; T[2][4] = y * y % mod;
	T[3][1] = 2 * x % mod * y % mod; T[3][3] = y; T[3][4] = 2 * x % mod * y % mod;
	T[4][4] = 1;

	Mtx B(1, 4);
	B[1][1] = a2 * a2 % mod; B[1][2] = a1 * a1 % mod;
	B[1][3] = a1 * a2 % mod; B[1][4] = (a1 * a1 % mod + a2 * a2 % mod) % mod;

	T = T ^ (n - 2);

	cout << (B * T)[1][4] % mod << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}