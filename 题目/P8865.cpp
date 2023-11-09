#include <iostream>
#include <algorithm>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

constexpr int N = 1e3 + 10;
constexpr int M = 1e3 + 10;
constexpr int mod = 998244353;

int n, m, c, f, id;
char g[N][N];
int sum[N][N];
int sumC[N][N];
i64 cntC, cntF;


inline void solve()
{
	cin >> n >> m >> c >> f;

	rep (i, 1, n) cin >> (g[i] + 1);

	rep (i, 1, n) per (j, m - 1, 1) // 反向枚举到 C 的左边两个顶点
		sum[i][j] = (g[i][j] == '1' ? -1 : (g[i][j + 1] == '0' ? sum[i][j + 1] + 1 : 0));

	rep (j, 1, m - 1)
	{
		int prvC = 0, prvF = 0;
		rep (i, 1, n)
		{
			if (!~sum[i][j]) { prvC = prvF = 0; continue; }

			cntC = (cntC + 1ll * sum[i][j] * prvC % mod) % mod;
			cntF = (cntF + prvF % mod) % mod;

			prvF = (prvF + 1ll * sum[i][j] * prvC % mod) % mod;
			prvC += max(0, sum[i - 1][j]);
		}
	}


	cout << cntC * c % mod << " ";
	cout << cntF * f % mod << endl;
}

inline void clear()
{
	cntC = cntF = 0;
	rep (i, 1, n) fill(sum[i], sum[i] + m + 1 , 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T >> id;
	while (T--) solve(), clear();
	return 0;
}