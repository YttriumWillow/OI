#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 51;
const int mod = 1e9 + 7;

int n, res; i64 k;

struct Mtx
{
	int a[N][N] = { 0 };
	friend Mtx	operator * (Mtx& A, Mtx& B)
	{
		Mtx res;
		rep (i, 1, n) rep (j, 1, n) rep (k, 1, n)
			res.a[i][j] = (res.a[i][j] + 1ll * A.a[i][k] * B.a[k][j] % mod) % mod;
		return res;
	}
	friend Mtx operator ^ (Mtx& A, i64 k)
	{
		Mtx res;
		rep (i, 1, n) res.a[i][i] = 1;
		for (; k; k >>= 1)
		{
			if (k & 1) res = res * A;
			A = A * A;
		}
		return res;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	Mtx M;
	rep (i, 1, n) rep (j, 1, n)
		cin >> M.a[i][j];
	M = M ^ k;
	rep (i, 1, n) rep (j, 1, n)
		res = (res + M.a[i][j]) % mod;
	cout << res << endl;
	return 0;
}