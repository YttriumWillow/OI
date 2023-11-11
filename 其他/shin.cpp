#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define int unsigned long long
#define ull unsigned long long

using namespace std;

const int mod = 1e9 + 7;

ull n, a1, a2, x, y;

struct matrix
{
	ull n, m, mtx[22][22];
	matrix() { memset(mtx, 0, sizeof mtx); }
	void clr() { memset(mtx, 0, sizeof mtx); }
} a, b, ans;

void init()   // 初始化 base 矩阵
{
	a.n = a.m = 4;
	b.n = 4, b.m = 1;
	a.mtx[1][1] = a.mtx[1][2] = a.mtx[3][2] = 1;
	a.mtx[2][2] = x * x % mod;
	a.mtx[2][3] = y * y % mod;
	a.mtx[2][4] = 2 * x * y % mod;
	a.mtx[4][2] = x;
	a.mtx[4][4] = y;
	b.mtx[1][1] = b.mtx[3][1] = a1 * a1 % mod;
	b.mtx[2][1] = a2 * a2 % mod;
	b.mtx[4][1] = a2 * a1 % mod;
}

matrix mul(matrix a, matrix b)   // 矩阵乘法
{
	matrix res;
	res.n = a.n, res.m = b.m;
	for (int i = 1; i <= a.n; ++ i)
		for (int j = 1; j <= a.m; ++ j)
			for (int k = 1; k <= b.m; ++ k)
				res.mtx[i][j] = (res.mtx[i][j] + a.mtx[i][k] * b.mtx[k][j]) % mod;
	return res;
}

void qpow(matrix a, ull n)
{
	ans = a;
	for (; n; n >>= 1)
	{
		if (n & 1) 
			ans = mul(ans, a); 
		a = mul(a, a);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; for (cin >> t; t; -- t)
	{
		a.clr(); b.clr(); ans.clr();
		cin >> n >> a1 >> a2 >> x >> y;
		a1 %= mod, a2 %= mod, x %= mod, y %= mod;
		if (n == 1) { cout << a1 * a1 % mod << '\n'; continue; }
		init(); qpow(a, n - 2); ans = mul(ans, b);
		cout << ans.mtx[1][1] << '\n';
	}
	return 0;
}
