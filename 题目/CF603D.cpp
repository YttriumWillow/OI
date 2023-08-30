#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define equal(p, q) (fabs((p) - (q)) < eps)
#define sqr(x) ((x) * (x))

using namespace std;

const int N = 3e3 + 10;
const double eps = 1e-12;

struct Point
{
	double x, y; 
	friend bool operator == (const Point &a, const Point& b)
	{ return equal(a.x, b.x) && equal(a.y, b.y); }
};

int n;
double k[N];
i64 ans;
Point rt[N];

int main()
{
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		double a, b, c; cin >> a >> b >> c;
		double d = sqr(a) + sqr(b);
		rt[i] = { b * c / d, a * c / d };
	}
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0, sme = 0;
		for (int j = i + 1; j <= n; ++j)	
		{
			if (rt[i] == rt[j])
				ans += n - i - (++sme);
			else
				k[++cnt] = equal(rt[i].x, rt[j].x) ? 1e18 : (rt[i].y - rt[j].y) / (rt[i].x - rt[j].x); 
		}
		sort(k + 1, k + cnt + 1);
		for (int j = 1, lst = 1; j <= cnt; ++j)
			equal(k[j], k[lst]) ? ans += (j - lst) : lst = j;
	}

	cout << ans << endl;
	return 0;
}