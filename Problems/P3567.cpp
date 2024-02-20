#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

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
}
using namespace bufIO;

const int N = 5e5 + 10;

int n, c, m, siz, a[N];
struct Node { int m, cnt; } t[N * 3];
inline Node merge(Node &a, Node &b)
{
    static Node res;
    if (a.m == b.m) { res = { a.m, a.cnt + b.cnt }; }
    else
    {
        if (a.cnt > b.cnt) res = {a.m, a.cnt - b.cnt};
        else res = {b.m, b.cnt - a.cnt};
    }
    return res;
}
inline void build()
{
    siz = 1;
    while (n + 2 > siz) siz <<= 1;
    int l = siz + 1, r = siz + n;
    for (int i = l; i <= r; ++i) t[i] = Node{a[i - siz], 1};
    l >>= 1, r >>= 1;
    while (l != r)
    {
        rep (i, l, r) t[i] = merge(t[i << 1], t[(i << 1) | 1]);
        l >>= 1, r >>= 1;
    }
    t[1] = merge(t[2], t[3]);
}
Node res;
inline void qry(int l, int r)
{
    int ss = siz + l - 1, tt = siz + r + 1;
    res = Node{0, 0};
    while (ss || tt)
    {
        if ((ss >> 1) ^ (tt >> 1)) // s/2 != t/2
        {
            if (!(ss & 1)) res = merge(res, t[ss ^ 1]);
            if (tt & 1) res = merge(res, t[tt ^ 1]);
        }
        else break;
        ss >>= 1; tt >>= 1;
    }
}
vector<int> v[N];

int main()
{
    read(n, m); c = n;
    rep (i, 1, n)
    {
        read(a[i]);
        v[a[i]].emplace_back(i);
    }
    build();
    while (m--)
    {
        int l, r; read(l, r); qry(l, r);
        if (upper_bound(v[res.m].begin(), v[res.m].end(), r)
            - lower_bound(v[res.m].begin(), v[res.m].end(), l) <= ((r - l + 1) >> 1))
            writeln(0);
        else writeln(res.m);
    }
    return flushout(), 0;
}