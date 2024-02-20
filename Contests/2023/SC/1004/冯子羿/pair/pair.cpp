#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

#define lowbit(x) ((x) & -(x))

using namespace std;

const int N = 1e6 + 10;
const int V = 60;

int n, m, a[N];
i64 cnt, res[N];
int blk, tot, bel[N];

namespace IO
{
#define reg register
template<typename _Tp>
inline void read(_Tp& x)
{
	x = 0; char c = getchar(); bool f = 0;
	while (!std::isdigit(c)) f |= c == 45, c = getchar();
	while ( std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
	return f ? x = -x : 1, void();
}
template<typename _Tp>
inline void write(_Tp x)
{
	static char stk[40]; int top = 0;
	if (!x)     return putchar(48), void();
	if (x < 0)  putchar(45), x = -x;
	while (x)   stk[top++] = x % 10, x /= 10;
	while (top) putchar(stk[--top] + 48);
}
// read
template<typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
} using namespace IO;

namespace BIT
{
int t[V], siz;
inline void add(int k, int v)
{
	for (int i = k; i <= V - 5; i += lowbit(i))
		t[i] += v;
	siz += v; // tmd ??䳤?????
}
inline int query(int k)
{
	int res = 0;
	for (int i = k; i; i -= lowbit(i))
		res += t[i];
	return res;
}
} using namespace BIT;

inline void blocking()
{
	blk = (int)sqrt(n);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
		for (int j = (i - 1) * blk + 1; j <= i * blk; ++j)
			bel[j] = i;
}

struct Qry
{
	int l, r, id;
	inline friend bool operator < (const Qry& x, const Qry& y)
	{ return (bel[x.l] ^ bel[y.l]) ? (bel[x.l] < bel[y.l]) : ((bel[x.l] & 1) ? x.r < y.r : x.r > y.r); }
} qry[N];

inline void solve()
{
	int l = 1; int r = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (r < qry[i].r) { ++r; cnt += siz - query(a[r]);	add(a[r], 1); } // add(++r);
		while (l > qry[i].l) { --l; cnt += query(a[l] - 1);		add(a[l], 1); } // add(--l);
		while (l < qry[i].l) { add(a[l], -1); cnt -= query(a[l] - 1);	++l; } // del(l++);
		while (r > qry[i].r) { add(a[r], -1); cnt -= siz - query(a[r]);	--r; } // del(r--);
		res[qry[i].id] = cnt;
	}
}

int main()
{
	file("pair");

	read(n, m); blocking();
	for (int i = 1; i <= n; ++i)
		read(a[i]);

	for (int i = 1; i <= m; ++i)
		read(qry[i].l, qry[i].r), qry[i].id = i;

	sort(qry + 1, qry + m + 1);
	solve();

	for (int i = 1; i <= m; ++i)
		write(res[i]), putchar('\n');

	return 0;
}

