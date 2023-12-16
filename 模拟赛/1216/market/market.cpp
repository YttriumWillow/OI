#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, r, l) for(int i = (r); i >= (l); --i)

using namespace std;

const int N = 310;
const int M = 1e5 + 10;

struct Shop
{
	int v, c, t; // U R right but v represents value
				 // c represents time cost
	friend bool operator < (const Shop& A, const Shop& B)
		{ return A.t < B.t; }
} shop[N];

struct Qry
{
	int t, m, id;
	friend bool operator < (const Qry& A, const Qry& B)
		{ return A.t < B.t; }
} qry[M];

int n, m;
int f[N * N], res[M];

inline void value(int cur)
{
	per (i, 90000, shop[cur].c)
		f[i] = min(f[i], f[i - shop[cur].c] + shop[cur].v);
    per (i, 90000, 1)
    	f[i] = min(f[i], f[i + 1]);
}

int main()
{
	file("market");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, n)
	{
		int x, y, z; cin >> x >> y >> z;
		shop[i] = { x, y, z };
	}

	sort(shop + 1, shop + n + 1);

	rep (i, 1, m)
	{
		int x, y; cin >> x >> y;
		qry[i] = { x, y, i };
	}

	sort(qry + 1, qry + m + 1);

	fill(f + 1, f + 90010, 0x3f3f3f3f);

	int cur = 1;
	rep (i, 1, m)
	{
		while (shop[cur].t <= qry[i].t && cur <= n)
            value(cur), ++cur;
        res[qry[i].id] = upper_bound(f, f + 90001, qry[i].m) - f - 1;
	}

	rep (i, 1, m)
		cout << res[i] << endl;

	return 0;
}