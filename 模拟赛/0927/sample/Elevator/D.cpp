#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 23;
const int mod = 998244353;

int n, a[N], sum[1 << N], ans;
int f1[1 << N], f2[1 << N];

signed main()
{
	file("Elevator");

	// 你说得对但是为什么安静值有负数 /cf

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	f1[0] = f2[0] = 1;

	for (int st = 0; st < (1 << n); ++st)
		for (int i = 1; i <= n; ++i)
			if ( (st >> (i - 1)) & 1 )
				sum[st] = (sum[st] + a[i]) % mod;

	for (int st = 0; st < (1 << n); ++st)
		for (int i = 1; i <= n; ++i)
			if (!((st >> (i - 1)) & 1))
			{
				// woc tmd 这里写 if/else 怎么这么丑啊
				// upd: 开摆了换个写法这样好看点。
				int *f = (sum[st] + a[i] >= 0 ? f1 : f2);
				f[st | (1 << (i - 1))] = (f[st | (1 << (i - 1))] + f[st]) % mod;
			}

	for (int i = 1; i <= n; ++i)
		for (int st = 0; st < (1 << n); ++st)
			if (!((st >> (i - 1)) & 1))
				ans = ( ans + 1ll
					* f1[st] * f2[((1 << n) - 1) ^ (st | (1 << (i - 1)))] % mod
					* sum[ st | (1 << (i - 1)) ] % mod
				) % mod; // 去 ** 的乘法缺个 1ll 浪费我时间

	cout << (ans % mod + mod) % mod << endl;

	return 0;
}