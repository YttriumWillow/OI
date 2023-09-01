// Problem:       P5503 [JSOI2016] 灯塔
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P5503
// Memory Limit:  500 MB
// Time Limit:    2000 ms
// Created Time:  2023-08-05 10:45:29 

// Problem:       P3515 [POI2011] Lightning Conductor
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P3515
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-08-05 10:05:06 

#include <bits/stdc++.h>

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

const int N = 5e5 + 10;
const int LOG = 18;

int n, m;
int lg[N], f[N];
int st[N][LOG];

inline void init()
{
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;
	for (int k = 1; k <= lg[n]; ++k)
		for (int i = 1; i + (1 << k) - 1 <= n; ++i)
			st[i][k] = max( st[i][k - 1], st[i + (1 << (k - 1))][k - 1] );
}

inline int query(int l, int r)
{
	if (l > r) return -1;
	int lgg = lg[r - l + 1];
	return max(st[l][lgg], st[r - (1 << lgg) + 1][lgg]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; ++i)
		read(st[i][0]);
	init();
	for (int i = 1; i <= n; ++i)
		for (int l = i, r = i, d = 0; r >= 1; r = l - 1, ++d, l = i - d * d)
			f[i] = max(f[i], query(max(1, l), r) + d);
	for (int i = n; i >= 1; --i)
		for (int l = i, r = i, d = 0; l <= n; l = r + 1, ++d, r = i + d * d)
			f[i] = max(f[i], query(l, min(r, n)) + d);
	
	for (int i = 1; i <= n; ++i)
		writeln(f[i] - st[i][0]);
	flushout();
	return 0;
}