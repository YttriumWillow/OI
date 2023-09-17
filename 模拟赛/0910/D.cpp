#include <iostream>
#include <ctime>
#include <random>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

int n, ans = inf, a[N];

namespace _20pts
{
inline void dfs(int i, int res, int st, int ed)
{
	if (i > n) { ans = min(ans, res); return; }
	if (res > ans) return;
	dfs(i + 1, max( res, abs(a[i] - st) ) , a[i], ed);
	dfs(i + 1, max( res, abs(a[i] - ed) ) , st, a[i]);
}
}

namespace Random
{
const double TIMELIMIT = 0.85;
inline void run()
{
	int st = a[1], ed = a[1], res = 0;
	for (int i = 1; i <= n; ++i)
	{
		bool p = rand() & 1;
		res = max(res, abs( a[i] - (p ? st : ed) ));
		p ? st = a[i] : ed = a[i];
	}
	ans = min(ans, res);
}
inline void QiDong()
{
	int t = 0;
	while ((double)clock() / CLOCKS_PER_SEC < TIMELIMIT) ++t, run();
	cerr << t << endl;
	cout << ans << endl;
}
}

namespace SA
{
const double d = 0.99;
const double T0 = 1e4;
const double TE = 1e-4;
const double TIMELIMIT = 0.85;
inline double frnd(double l, double r) { return 1.0 * rand() / RAND_MAX * (r - l) + l; }
inline int rnd(int r) { return rand() % (r) + 1; }
bool bel[N];
inline double calc()
{
	int st = a[1], ed = a[1], res = 0;
	for (int i = 2; i <= n; ++i)
	{
		bool p = bel[i];
		res = max(res, abs( a[i] - (p ? st : ed) ));
		p ? st = a[i] : ed = a[i];
	}
	ans = min(ans, res);
	return res;
}
inline void run()
{
	for (int i = 1; i <= n; ++i)
		bel[i] = i & 1;
	for (double T = T0; T >= TE; T *= d)
	{
		int p = rnd(n);
		double prev = calc();
		bel[p] ^= 1;
		double suff = calc();

		if (exp(-(suff - prev) / T) > frnd(0, 1)) {}
		else { bel[p] ^= 1; }
	}
}
inline void QiDong()
{
	int t = 0;
	while ((double)clock() / CLOCKS_PER_SEC < TIMELIMIT) ++t, run();
	cerr << t << endl;
	cout << ans << endl;
}
}

int main()
{
	// file("D");
	srand(time(0));

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	_20pts::dfs(2, 0, a[1], a[1]);
	cout << ans << endl;
	return 0;
}