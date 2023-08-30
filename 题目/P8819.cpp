// Problem:      P8819 [CSP-S 2022] 星战
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8819
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-05 10:03:46 

#include <iostream>

#include <ctime>
#include <random>

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

const i64 N = 5e5 + 10;

mt19937 rnd(time(0));

i64 n, m, q;
i64 opt, u, v;
i64 r[N], w[N], g[N];
i64 sum, chk;

int main()
{
	read(n, m);
	for (int i = 1; i <= n; ++i)
		w[i] = rnd(), chk += w[i];
	for (int i = 1; i <= m; ++i)
	{
		read(u, v);
		r[v] += w[u];
		g[v] = r[v];
		sum += w[u];
	}
	
	read(q);
	for (int i = 1; i <= q; ++i)
	{
		read(opt);
		if (opt == 1)
		{
			read(u, v);
			r[v] -= w[u];
			sum -= w[u];
		}
		if (opt == 2)
		{
			read(v);
			sum -= r[v];
			r[v] = 0;
		}
		if (opt == 3)
		{
			read(u, v);
			r[v] += w[u];
			sum += w[u];
		}
		if (opt == 4)
		{
			read(v);
			sum += g[v] - r[v];
			r[v] = g[v];
		}
		
		puts(sum == chk ? "YES" : "NO");
	}
	return 0;
}