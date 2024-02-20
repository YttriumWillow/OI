#include <iostream>
#include <iomanip>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define sqr(x) ((x) * (x)) 
// using sqr(x) = ((x) * (x));

using namespace std;

const int N = 21;

int n, m, a[N];

#include <algorithm>
#include <random>
#include <ctime>
double ans = 1e18;
namespace SA
{
inline double update(double x) { return ans = min(ans, x); }
inline double calc()
{
	static int cnt[N];
	fill(cnt + 1, cnt + n + 1, 0);
	for (int i = 1, g = 1; i <= n; ++i, g = 1)
	{
		for (int j = 1; j <= m; ++j)
			if (cnt[g] > cnt[j]) g = j;
		cnt[g] += a[i];
	}
	double bar = 0, res = 0;
	for (int i = 1; i <= m; ++i)
		bar += 1.0 * cnt[i];
	bar /= m;
	for (int i = 1; i <= m; ++i)
		res += sqr(cnt[i] - bar);
	res /= m; res = sqrt(res);
	return res;
}

// 随机函数
mt19937 seed(random_device{}());
uniform_real_distribution<> _01rnd(0, 1);

// 参数集
const double d = 0.99;  // 降温系数 
const double T0 = 1e4; // 初始温度
const double TE = 1e-4; // 终止温度
const double TIMELMT = 0.5; // 跑退火时间
const double ROUND = 114; // 跑退火次数

inline void run()
{
	uniform_int_distribution<> rndpos(1, n);
	shuffle(a + 1, a + n + 1, seed);

	for (double T = T0; T >= TE; T *= d)
	{
		int p = rndpos(seed);
		int q = rndpos(seed);

		double prev = update(calc());
		swap(a[p], a[q]);
		double suff = update(calc());

		if (exp(-(suff - prev) / T) < _01rnd(seed))
			swap(a[p], a[q]);
	}
}
inline void timerun(double t = TIMELMT) { while((double)clock() / CLOCKS_PER_SEC < t) run(); }
inline void roundrun(int t = ROUND) { while(t--) run(); }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	SA::roundrun();
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}