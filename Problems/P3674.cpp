#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#include <cstring>
namespace bufIO
{
const int _Pu = 1 << 16;
const int _d = 32;
char buf[_Pu], obuf[_Pu];
char *inl = buf + _Pu, *inr = buf + _Pu;
char *outl = obuf, *outr = obuf + _Pu - _d;
inline void flushin()
{
	memmove(buf, inl, inr - inl);
	int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
	if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
	inl = buf;
}
inline void flushout() { fwrite(obuf, outl - obuf, 1, stdout), outl = obuf; }
template <typename _Tp>
inline void read(_Tp &x)
{
	if (inl + _d > inr) { flushin(); }
	int isne = 0;
	for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
	x = (*inl++ - '0');
	for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
	if (isne) { x = -x; }
}
template <typename _Tp>
inline void writeln(_Tp x, char end = '\n')
{
	if (outl > outr) { flushout(); }
	if (x < 0) { *outl++ = '-'; x = -x; }
	char sta[20]; char *top = sta;
	do { *top++ = (x % 10) + '0'; x /= 10; }
	while (x);
	do { *outl++ = *--top; }
	while (top != sta);
	(*outl++) = end;
}
template<typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int N = 1e5 + 10;

int n, m, a[N], buc[N];
bool cnt, res[N];
bitset<N> ex1, ex2;
int blk, tot, bel[N];

inline void blocking()
{
	blk = (int)sqrt(n) + 1;
	tot = n / blk + !!(n % blk);
	// cerr << "?" << endl;
	for (int i = 1; i <= tot; ++i)
		for (int j = (i - 1) * blk + 1; j <= i * blk && j <= n; ++j)
			bel[j] = i;
	// cerr << "blked" << endl;
}

struct Qry
{
	int t, l, r, x, id;
	inline friend bool operator < (const Qry& x, const Qry& y)
	{ return (bel[x.l] ^ bel[y.l]) ? bel[x.l] < bel[y.l] : ((bel[x.l] & 1) ? x.r < y.r : x.r > y.r); }
} qry[N];

inline void add(int x)
{
	int &v = a[x];
	if (n < v) return;
	if (!buc[v]++) ex1[v] = ex2[n - v] = 1;
}

inline void del(int x)
{
	int &v = a[x];
	if (n < v) return;
	if (!--buc[v]) ex1[v] = ex2[n - v] = 0;
}

inline void solve()
{
	int l = qry[1].l, r = l - 1;
	for (int i = 1; i <= m; ++i)
	{
		int &t = qry[i].t;
		int &x = qry[i].x;

		while (l < qry[i].l) del(l++);
		while (l > qry[i].l) add(--l);
		while (r > qry[i].r) del(r--);
		while (r < qry[i].r) add(++r);

		bool &r = res[qry[i].id];
		if (t == 1)
		{
			// cerr << "!" << endl;
			r = (ex1 & (ex1 << x)).any();
			// cerr << "f1" << endl;
		}
		else if (t == 2)
			r = (ex1 & (ex2 >> (n - x))).any();
		else
		{
			for (int p = 1; p * p <= x; ++p)
				if (!(x % p))
					if (ex1[p] && ex1[x / p])
						{ r = 1; break; }
		}
	}
}

int main()
{
	read(n, m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);

	for (int i = 1; i <= m; ++i)
	{
		int opt, l, r, x;
		read(opt, l, r, x);
		qry[i] = { opt, l, r, x, i };
	}

	blocking();

	sort(qry + 1, qry + m + 1);
	solve();

	for (int i = 1; i <= m; ++i)
		puts(res[i] ? "hana" : "bi");

	return 0;
}