#pragma GCC optimize(2)

#include <iostream>
#include <cmath>
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
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int N = 3e4 + 200;
const int C = 1e6 + 10;
const int Q = 2e5 + 10;

int n, q, a[N];
int cnt, buc[C];
int res[Q];

int blk, tot, bel[N];
inline void init(int n)
{
	blk = (int)sqrt(n);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
		for (int j = (i - 1) * blk + 1; j <= i * blk; ++j)
			bel[j] = i;
}

struct Query
{
	int l, r, id;
	friend bool operator < (const Query& _x, const Query& _y)
	{ return (bel[_x.l] ^ bel[_y.l]) ? bel[_x.l] < bel[_y.l] : ((bel[_x.l] & 1) ? _x.r < _y.r : _x.r > _y.r); }
} qry[Q];

inline void solve()
{
	int l = 1, r = 0;
	for (int i = 1; i <= q; ++i)
	{
		while (l < qry[i].l) cnt -= !--buc[a[l++]];
		while (l > qry[i].l) cnt += !buc[a[--l]]++;
		while (r < qry[i].r) cnt += !buc[a[++r]]++;
		while (r > qry[i].r) cnt -= !--buc[a[r--]];
		res[qry[i].id] = cnt;
	}
}
int main()
{
	read(n); init(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	read(q);
	for (int i = 1; i <= q; ++i)
		read(qry[i].l, qry[i].r), qry[i].id = i;

	sort(qry + 1, qry + q + 1);
	solve();

	for (int i = 1; i <= q; ++i)
		writeln(res[i]);
	flushout();
	return 0;
}