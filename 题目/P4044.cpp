#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define fir first
#define sec second

using namespace std;

const int N = 100;

int n, m, ans;
pair<int, int> a[N];

const double d = 0.98;
const double T0 = 1e4;
const double TE = 1e-4;
const int ROUND = 12;

inline int rndpos() { return rand() % m + 1; }
inline double rndf(double l, double r) { return 1.0 * rand() / RAND_MAX * (r - l) + l; }
inline int calc()
{
	m = n + (a[n].fir == 10);
	int res = 0;
	for (int i = 1; i <= m; ++i)
	{
		res += a[i].fir + a[i].sec;
		if (i > n) continue;
		if (a[i].fir == 10)
			res += a[i + 1].fir + a[i + 1].sec;
		else if (a[i].fir + a[i].sec == 10)
			res += a[i + 1].fir;
	}
	ans = max(ans, res);
	return res;
}
inline void run()
{
	m = n + (a[n].fir == 10);
	for (double T = T0; T >= TE; T *= d)
	{
		int p = rndpos(), q = rndpos();

		int prev = calc();
		swap(a[p], a[q]);
		if (n + (a[n].fir == 10) == m)
		{
			int suff = calc();
			if (exp((suff - prev) / T) < rndf(0, 1))
				swap(a[p], a[q]);
		}
		else swap(a[p], a[q]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	srand(time(0));

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].fir >> a[i].sec;
	if (a[n].fir == 10)
		cin >> a[n + 1].fir >> a[n + 1].sec;
	int p = ROUND;
	while (p--) run();
	cout << ans << endl;
	return 0;	
}