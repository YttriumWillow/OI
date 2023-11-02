#include <iostream>
#include <cstring>

#define int long long
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

namespace MillerRabin
{
// quick power
inline i64 qpow(i64 a, i64 n, const i64 P)
{
	i64 res = 1;
	do {
		if (n & 1) res = res * a % P;
		a = a * a % P;
	} while (n >>= 1);
	return res;
}
inline bool isprime(i64 n)
{
	if (n < 3) return n == 2;
	if ((n & 1) == 0)  return false;
	static const i64 A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
	i64 t = n - 1, h = 0;
	h = __builtin_ctz(t); t >>= h;
	for (i64 a : A)
	{
		a %= n;
		if (a <= 1) continue;
		i64 v = qpow(a, t, n);
		if (v == 1 || v == n - 1) continue;
		for (int i = 1; i <= h; i++)
		{
			v = v * v % n;
			if (v == n - 1 && i != h) { v = 1; break; }
			if (v == 1) return false;
		}
		if (v != 1) return false;
	}
	return true;
}
} using namespace MillerRabin;

const int N = 1e5 + 10;
int T, n, k;

inline int calc(int n)
{
	if (n == 0) return 0;
	if (n == 1) return (k - 1) * (k - 1);
	for (int p = n; p; --p)
		if (isprime(p))
			return max(p * (k - 1) * (k - 1), (p - k) * (p - k)) + calc(n - p);	
	return 0;
}

inline void solve()
{
	read(n, k);
	if (n == 1)
		writeln((k - 1) * (k - 1));
	else if (isprime(n))
		writeln(max((n - k) * (n - k), n * (k - 1) * (k - 1)));
	else
		writeln(max(calc(n), n * (k - 1) * (k - 1)));
}

signed main()
{
	int T; for (read(T); T--;) solve();
	return flushout(), 0;
}