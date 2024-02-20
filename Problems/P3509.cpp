#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

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
} using namespace bufIO;

const int N = 1e6 + 10;

int n, k, m;
i64 x[N];
int nxt[N], t[N], pos[N];

int main()
{
	read(n, k, m);
	rep (i, 1, n) read(x[i]);

	nxt[1] = k + 1; int H = 1, T = k + 1;
	rep (i, 1, n)
	{
		while (T < n and x[T + 1] - x[i] < x[i] - x[H])
			++H, ++T;
		if (x[T] - x[i] > x[i] - x[H])
			nxt[i] = T;
		else nxt[i] = H;
	}

	rep (i, 1, n) pos[i] = i;

	for (; m; m >>= 1)
	{
		if (m & 1)
			rep (i, 1, n) pos[i] = nxt[pos[i]];
		rep (i, 1, n) t[i] = nxt[i];
		rep (i, 1, n) nxt[i] = t[t[i]];
	}

	rep (i, 1, n)
		writeln(pos[i], " \n"[i == n]);

	return flushout(), 0;
}