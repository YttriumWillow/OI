#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define sqr(x) ((x) * (x))

#define prob "geometry"

using namespace std;

const int N = 3e3 + 10;
const double eps = 1e-3;

int n, ans;

struct Line { double a, b, c; };
struct Point { double x, y; };

Line l[N];

#define equal(x, y) (fabs((x) - (y)) < eps)

inline int chk(int i, int j, int k)
{
	Line& l1 = l[i];
	Line& l2 = l[j];
	Line& l3 = l[k];

	double x, y;

	x = (l2.c * l1.b - l1.c * l2.b) / (l1.a * l2.b - l2.a * l1.b);
	y = (l1.c * l2.a - l2.c * l1.a) / (l1.a * l2.b - l2.a * l1.b);

	Point p1 = { x, y };
 	
	x = (l2.c * l3.b - l3.c * l2.b) / (l3.a * l2.b - l2.a * l3.b);
	y = (l3.c * l2.a - l2.c * l3.a) / (l3.a * l2.b - l2.a * l3.b);

	Point p2 = { x, y };

	x = (l1.c * l3.b - l3.c * l1.b) / (l3.a * l1.b - l1.a * l3.b);
	y = (l3.c * l1.a - l1.c * l3.a) / (l3.a * l1.b - l1.a * l3.b);

	Point p3 = { x, y };

	double d1 = (sqr(p2.x) + sqr(p2.y)) - (sqr(p1.x) + sqr(p1.y));
	double d2 = (sqr(p3.x) + sqr(p3.y)) - (sqr(p2.x) + sqr(p2.y));
    double fm = 2 * ((p3.y - p2.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p2.x));
    x = ((p3.y - p2.y) * d1 - (p2.y - p1.y) * d2) / fm;
    y = ((p2.x - p1.x) * d2 - (p3.x - p2.x) * d1) / fm;

    Point center = { x, y };

    if ( equal(sqr(center.x) + sqr(center.y), sqr(center.x - p1.x) + sqr(center.y - p1.y)) )
    	return 1;
    return 0;
}

int main()
{
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> l[i].a >> l[i].b >> l[i].c;

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k)
				ans += chk(i, j, k);

	cout << ans << endl;
	return 0;
}