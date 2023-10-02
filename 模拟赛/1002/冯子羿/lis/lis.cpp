#include <iostream>
#include <cstdio>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 1e7 + 10;
const int mod = 998244353;

using namespace std;

using std::min;
static inline int __my_rand(int *seed)
{
    *seed = *seed * 1103515245 + 12345;
    return ((unsigned) * seed) / 34;
}
int gen(int N, int Lim, int seed, int* F)
{
    int cur = 0;
    for (int i = 1; i <= N; i ++)
    {
        int rd = __my_rand(&seed);
        if (rd % std::min(10, cur + 1) == 0 && cur < Lim) F[i] = ++cur;
        else F[i] = (__my_rand(&seed) % cur) + 1;
    }
    return 0;
}

int n, lim, seed, f[N];
int a[N], ans[N], B[N];

inline bool chk()
{
	static int dp[N];
	fill(dp, dp + n + 1, 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
	for (int i = 1; i <= n; ++i)
		if (f[i] != dp[i])
			return false;
	return true;
}

int main()
{
	file("lis");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> lim >> seed;

    gen(n, lim, seed, f);

    for (int i = 1; i <= n; ++i)
    	a[i] = i;

    do {
    	if (chk())
    	{
    		for (int i = 1; i <= n; ++i)
    			ans[i] = max(ans[i], a[i]);
    	}
    } while (next_permutation(a + 1, a + n + 1));

    for (int i = 1; i <= n; ++i)
    	cerr << ans[i] << " \n"[i == n];

    int res = 0; B[0] = 1;
    for (int i = 1; i <= n; ++i)
    	B[i] = 1ll * B[i - 1] * 131 % mod;
    for (int i = 1; i <= n; ++i)
    	res = (res + 1ll * B[i] % mod * ans[i] % mod) % mod;

    cout << res << endl;

    return 0;
}
