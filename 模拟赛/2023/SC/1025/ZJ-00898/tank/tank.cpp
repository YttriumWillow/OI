#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 3e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 n, m, a, b;
i64 x[N], y[N], B, r;
i64 S[4][N];

#define ls (p << 1)
#define rs (p << 1 | 1)
struct Node { int l, r; i64 v[4]; } t[N << 2], res;

inline void update(Node &x, Node& y)
{
	x.v[0] = max(x.v[0], y.v[0]);
	x.v[1] = max(x.v[1], y.v[1]);
	x.v[2] = max(x.v[2], y.v[2]);
	x.v[3] = max(x.v[3], y.v[3]);
}

inline void pushup(int p)
{
	Node &T = t[p];
	rep (i, 0, 3) T.v[i] = max(t[ls].v[i], t[rs].v[i]);
}

inline void build(int p, int l, int r)
{
	Node &T = t[p];
	T.l = l, T.r = r;
	if (l == r) { rep (i, 0, 3) T.v[i] = S[i][l]; return; }
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void query(int p, int l, int r)
{
	Node &T = t[p];
	if (l <= T.l and T.r <= r) { update(res, T); return; }
	int mid = (T.l + T.r) >> 1;
	if (l <= mid) query(ls, l, r);
	if (mid <  r) query(rs, l, r);
}

int main()
{
	file("tank");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> a >> b;
	B = a * a + b * b;

	rep (i, 1, n)
	{
		cin >> x[i] >> y[i];
		i64 px = a * x[i] + b * y[i];
		i64 py = -b * x[i] + a * y[i];
		x[i] = px;
		y[i] = py;
	}

	rep (i, 1, n)
	{
		S[0][i] = x[i] + y[i];
		S[1][i] = x[i] - y[i];
 		S[2][i] = -x[i] + y[i];
		S[3][i] = -x[i] - y[i];
	}

	build(1, 1, n);

	rep (i, 1, m)
	{
		i64 l, r, p, q;
		cin >> l >> r >> p >> q;
		i64 pp = a * p + b * q;
		i64 pq = -b * p + a * q;
		p = pp; q = pq;

		res = { 0, 0, { -inf, -inf, -inf, -inf } };
		query(1, l, r); r = 0;

		r = max(r, res.v[0] - (p + q));
		r = max(r, res.v[1] - (p - q));
		r = max(r, res.v[2] - (-p + q));
		r = max(r, res.v[3] - (-p - q));
		
		i64 g = __gcd(r, B);
		cout << r / g << '/' << B / g << endl;
	}

	return 0;
}