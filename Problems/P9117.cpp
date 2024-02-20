// Problem:      P9117 [春季测试 2023] 涂色游戏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9117
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-08-16 11:23:39 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
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

int T, n, m, q;
int line[2][100010];
int pri[2][100010];

int main()
{
	read(T);
	while (T--)
	{
		read(n, m, q);
		for (reg int i = 1, opt, x, c; i <= q; ++i)
		{
			read(opt, x, c);
			line[opt][x] = c;
			pri[opt][x] = i;
		}
		for (reg int i = 1; i <= n; ++i)
		{
			for (reg int j = 1; j < m; ++j)
					writeln(line[(pri[0][i] < pri[1][j])][(pri[0][i] >= pri[1][j] ? i : j)], ' ');
			writeln(line[(pri[0][i] < pri[1][m])][(pri[0][i] >= pri[1][m] ? i : m)]);
		}
		memset(line, 0, sizeof line);
		memset(pri, 0, sizeof pri);
	}
	flushout();
	return 0;
}