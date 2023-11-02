#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

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

constexpr int N = 3e5 + 10;
constexpr int LG = 20;

int n, t, q;
int p[N], f[N], prv[N];
int st[LG][N];
char res[N];

inline void build(int n)
{
	rep (i, 1, n)
		st[0][i] = i + p[i];
	for (int k = 1; (1 << k) <= n; ++k)
		for (int i = 1; i + (1 << k) <= n + 1; ++i)
			st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}

inline int query(int l, int r)
{
	if (l > r) return -1;
	int k = __lg(r - l + 1);
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}

inline void solve()
{
	read(n);
	rep (i, 1, n) read(p[i]);
	build(n);

	prv[1] = 1;
	rep (i, 2, n)
	{
		if (!p[i])
		{
			f[i] = f[i - 1]; prv[i] = i;
			continue;
		}
		prv[i] = t = lower_bound(f, f + i, i - p[i] - 1) - f;
		if (t == i) f[i] = f[i - 1];
		else
		{
			f[i] = max(i - 1, query(t + 1, i - 1));
			if (f[i - 1] > f[i]) f[i] = f[i - 1], prv[i] = i;
			if (f[i - 1] >= i && i + p[i] > f[i])
			{
				f[i] = i + p[i];
				prv[i] = i;
			}
		}
	}

	if (f[n] < n) { puts("NO"); return; }
	puts("YES");
	int cur = n;
	while (cur)
	{
		if (prv[cur] == cur)
			res[cur] = 'R', --cur;
		else
		{
			res[cur] = 'L'; int pos = prv[cur];
			while (cur > pos) res[--cur] = 'R';
		}
	}
	rep (i, 1, n) putchar(res[i]); putchar(endl);
}

inline void clear() { fill(f, f + n + 1, 0); }

int main()
{
	int T; read(T);
	while (T--) solve(), clear();
	return 0;
}