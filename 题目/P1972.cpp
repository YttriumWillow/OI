#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO { static constexpr int SIZE = 1 << 21; char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf; inline void read(char& c) { for (c = gc(); !std::isgraph(c); c = gc()); } inline void read(char* s) { char c = gc(); for (; !std::isgraph(c); c = gc()); for (; std::isgraph(c); c = gc()) * s++ = c; *s = 0; } inline void read(std::string& s) { s.clear(); char c = gc(); for (; !std::isgraph(c); c = gc()); for (; std::isgraph(c); c = gc()) s.push_back(c); } inline void pc(char c) { if (p3 - obuf == SIZE) fwrite(obuf, 1, SIZE, stdout), p3 = obuf; *p3++ = c; } inline void write(char c) { pc(c); } inline void write(const char* s) { while (*s) pc(*s), ++s; } inline void write(std::string s) { for (const char c : s) pc(c); } template<typename _Tp>inline void read(_Tp& x) { x = 0; char c = gc(); int f = 0; for (; !std::isdigit(c); c = gc()) f |= c == '-'; for (; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48); return f ? x = ~x + 1 : 1, void(); } template<typename _Tp>inline void write(_Tp x) { static int stk[40]; int tp = 0; if (!x) return pc('0'), void(); if (x < 0) pc('-'), x = ~x + 1; while (x) stk[++tp] = x % 10, x /= 10; while (tp) pc(stk[tp--] + '0'); } template<typename _Tp>inline void writesp(_Tp x) { write(x), pc(' '); } template<typename _Tp>inline void writeln(_Tp x) { write(x), pc('\n'); } template<typename _Tp, typename ...Args>inline void read(_Tp& x, Args& ...args) { read(x), read(args...); } template<typename _Tp, typename ...Args>inline void write(_Tp x, Args ...args) { write(x), write(args...); } template<typename _Tp, typename ...Args>inline void writesp(_Tp x, Args ...args) { writesp(x), writesp(args...); } template<typename _Tp, typename ...Args>inline void writeln(_Tp x, Args ...args) { writeln(x), writeln(args...); } inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); } }
using namespace FastIO;

const int N = 1e6 + 2000;
const int C = 1e6 + 10;
const int Q = 1e6 + 10;

int n, q, a[N];
int cnt, buc[C];
int pre[N], suf[N];
int res[Q];

int blk, tot, bel[N];
inline void init(int n)
{
	blk = (int)pow(n, 0.5);
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
		while (r < qry[i].r) cnt += pre[++r] < l;
		while (l > qry[i].l) cnt += suf[--l] > r;
		while (r > qry[i].r) cnt -= pre[r--] < l;
		while (l < qry[i].l) cnt -= suf[l++] > r;
		res[qry[i].id] = cnt;
	}
}
int main()
{
	read(n); init(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);

	for (int i = 1; i <= n; ++i)
	{
		if (!buc[a[i]]) pre[i] = 0;
		else pre[i] = buc[a[i]];
		buc[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
		buc[a[i]] = 0;
	for (int i = n; i >= 1; --i)
	{
		if (!buc[a[i]]) suf[i] = n + 1;
		else suf[i] = buc[a[i]];
		buc[a[i]] = i;
	}

	read(q);
	for (int i = 1; i <= q; ++i)
		read(qry[i].l, qry[i].r), qry[i].id = i;

	sort(qry + 1, qry + q + 1);
	solve();

	for (int i = 1; i <= q; ++i)
		writeln(res[i]);
	flush();
	return 0;
}