#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 2e5 + 10;

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
inline _Tp read(_Tp &x)
{
	if (inl + _d > inr) { flushin(); }
	int isne = 0;
	for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
	x = (*inl++ - '0');
	for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
	if (isne) { x = -x; } return x;
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
} using namespace bufIO;

int n, m, q, tot, cnt;
int prv[N], col[N], id[N];
i64 res[N];
struct Qry { int ps, t, l, p; } qry[N << 1];

i64 t[N];
#define lowbit(x) ((x) & (-x))
inline void update(int x, int k)
{
	for (int i = x; i <= q; i += lowbit(i))
		t[i] += k;
}
inline i64 query(int x)
{
	if (!x) return 0;
	i64 ret = 0;
	for (int i = x; i; i -= lowbit(i))
		ret += t[x];
	return ret;
}

inline void modify(int i, int l, int r, int k)
{
	qry[++tot] = { l, i, k, -114 };
	qry[++tot] = { r + 1, i, -k, -114 };
}
inline void fix(int i, int x, int y) { prv[x] = i; col[x] = y; }
inline void fquery(int i, int x, int y)
{
	qry[++tot] = { y, i, prv[x], col[x] };
	id[i] = ++cnt;
}

int main()
{
	read(n, m, q);
	rep (i, 1, q)
	{
		int opt, a, b, c;
		switch (read(opt))
		{
		case 1: read(a, b, c); modify(i, a, b, c);
			break;
		case 2: read(a, b); fix(i, a, b);
			break;
		case 3: read(a, b); fquery(i, a, b);
			break;
		default: puts("Love for Nahida");
		}
	}
	sort(qry + 1, qry + tot + 1, [](Qry & x, Qry & y) { return x.ps != y.ps ? x.ps < y.ps : x.p < y.p; });
	rep (i, 1, tot)
	{
		if (qry[i].p == -114) update(qry[i].t, qry[i].l);
		else res[id[qry[i].t]] = query(qry[i].t) - query(qry[i].l) + qry[i].p;
	}
	rep (i, 1, cnt)
		writeln(res[i]);
	return flushout(), 0;
}