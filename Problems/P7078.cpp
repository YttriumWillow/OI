#include <iostream>
#include <cstring>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define value first
#define index second
#define Pii pair<int, int>

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

const int N = 1e6 + 5;

int n, k, x, y;
int a[N], eat[N], kll[N];
int res, cnt;
pair<i64, int> v[N];
bool sfe[N], del[N << 1];

inline void solve()
{
    priority_queue<Pii, vector<Pii>, less<Pii>   > Qmax(v + 1, v + n + 1);
    priority_queue<Pii, vector<Pii>, greater<Pii>> Qmin(v + 1, v + n + 1);

    res = n - 1; cnt = n;
    fill(sfe, sfe + n + 1, 0);
    fill(del, del + n + n + 1, 0);

    rep (i, 0, n - 2)
    {
        while (del[Qmax.top().index]) Qmax.pop();
        while (del[Qmin.top().index]) Qmin.pop();

        i64 vmax = Qmax.top().value, vmin = Qmin.top().value;
        kll[i] = vmin & 0xfffff; eat[i] = vmax & 0xfffff;

        Pii cur = { vmax - vmin + kll[i], ++cnt };
        del[Qmax.top().index] = del[Qmin.top().index] = 1;

        Qmax.pop(); Qmax.push(cur);
        Qmin.pop(); Qmin.push(cur);
    }

    for (int i = n - 2; ~i; --i)
    {
        if (sfe[eat[i]])
        {
            rep (j, i + 1, res - 1) sfe[kll[j]] = 0;
            res = i;
        }
        else sfe[kll[i]] = 1;
    } 
    writeln(n - res);
}

int main()
{
    int T; read(T, n); --T;
    rep (i, 1, n) { read(a[i]); v[i] = { (i64)a[i] << 20 | i, i }; }
    solve();
    while (T--)
    {
        read(k);
        while (k--) { read(x, y), a[x] = y, v[x] = { (i64)y << 20 | x, x }; }
        solve();
    }
    return flushout(), 0;
}