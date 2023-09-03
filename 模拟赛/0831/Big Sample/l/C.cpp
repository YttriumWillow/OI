#include <iostream>
#include <cstring>
#include <map>

// #define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 2333;
const int N = 41;

int n, m, q, res;
int S, T, l, r;

struct Mt
{
	int m[N][N] = { 0 };
	inline void set() { for (int i = 1; i <= n; ++i) m[i][i] = 1; }
	inline void clear() { memset(m, 0, sizeof m); }
	inline friend Mt operator * (const Mt& A, const Mt& B)
	{
		Mt res;
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k <= n; ++k)
			{
				if (A.m[i][k] == 0) continue;
				for (int j = 1; j <= n; ++j)
					res.m[i][j] = (res.m[i][j] + A.m[i][k] * B.m[k][j]) % mod;
			}
		return res;
	}
};

inline Mt operator ^ (Mt A, int k)
{
	Mt res; res.set();
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * A;
		A = A * A;
	}
	return res;
}

Mt G;

int main()
{
	freopen("l.in", "r", stdin);
	freopen("l.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		G.m[x][y] = G.m[y][x] = 1;
	}

	cin >> q;
	while (q--)
	{
		cin >> S >> T >> l >> r; res = 0;
		Mt X = (G ^ l); res = (res + X.m[S][T]) % mod;
		for (int i = l + 1; i <= r; ++i)
		{
			X = X * G;
			res = (res + X.m[S][T]) % mod;
		}
		cout << res << endl;
	}
	return 0;
}