#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 500;
const int Q = 1e5 + 500;

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
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

int n, q;
int a[N]; i64 b[N], len;
int buc[N]; i64 res[Q];
int blk, tot, bel[N];

struct Qry
{
	int l, r, id;
	inline friend bool operator < (const Qry& x, const Qry& y)
	{ return (bel[x.l] != bel[y.l]) ? (bel[x.l] < bel[y.l]) : (bel[x.r] < bel[y.r]); }
} qry[Q];

inline void blocking()
{
	blk = (int)sqrt(n);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
		for (int j = (i - 1) * blk + 1; j <= i * blk && j <= n; ++j)
			bel[j] = i;
}


inline void solve()
{
	int l = 0, r = 0;
	i64 cur = 0, lst = 0;
	for (int i = 1; i <= q; ++i)
	{
		l = bel[qry[i].l] * blk;

		if (bel[qry[i - 1].l] < bel[qry[i].l])
		{
			fill(buc + 1, buc + len + 1, 0);
			r = l - 1;
			lst = cur = 0;
		}

		cur = lst;
		while (r < qry[i].r)
		{
			++r; ++buc[a[r]];
			cur = max(cur, b[a[r]] * buc[a[r]]);
		}
		while (r > qry[i].r) { --buc[a[r]]; --r; }
		lst = cur;

		while (l > qry[i].l)
		{
			--l; ++buc[a[l]];
			cur = max(cur, b[a[l]] * buc[a[l]]);
		}

		res[qry[i].id] = cur;

		for (int j = bel[qry[i].l] * blk - 1; j >= l; --j)
			--buc[a[j]];
	}
}

signed main()
{
	read(n, q);
	for (int i = 1; i <= n; ++i)
		read(a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;

	for (int i = 1, l, r; i <= q; ++i)
	{
		read(l, r);
		qry[i] = { l, r, i };
	}

	// blocking();
	blk = (int)sqrt(n);
	for (int i = 1; i <= n; ++i)
		bel[i] = (i - 1) / blk + 1;
	sort(qry + 1, qry + q + 1);
	solve();

	for (int i = 1; i <= q; ++i)
		writeln(res[i]);
	flushout();
	return 0;
}