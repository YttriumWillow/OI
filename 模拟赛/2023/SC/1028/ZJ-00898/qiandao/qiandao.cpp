#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

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
} using namespace bufIO;

#define midp(l, r) (l - 1 + (int)((r - l + 1) / 2))

const int N = 2e6 + 10;
const int inf = 0x3f3f3f3f;

int n, a[N]; i64 res;
int prv[N];

namespace _60
{
inline void solve()
{
	rep (i, 1, n)
	{
		prv[i - 1] = inf;
		rep (j, i, n)
		{
			prv[j] = min(prv[j - 1], a[j]);
			if (prv[midp(i, j)] == prv[j])
			{
				// cerr << '[' << i << ", " << j << ']' << endl;
				++res; 
			}
		}
	}
	cout << res << endl;
}
}

int main()
{
	file("qiandao");

	read(n); 
	rep (i, 1, n) read(a[i]);

	reverse(a + 1, a + n + 1);

	if (n <= 5000) _60::solve(), exit(0);

	rep (i, 1, n) prv[i] = min(prv[i - 1], a[i]);

	// rep (i, 1, n)
	// {
	// 	while (!q.empty() && ____) do something.
	// 	then do something.
	// 	then blahblahblah...
	// }

	return 0;
}