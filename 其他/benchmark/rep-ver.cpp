#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO { static constexpr int SIZE = 1 << 21; char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf; inline void read(char& c) { for(c = gc(); !std::isgraph(c); c = gc()); } inline void read(char* s) { char c = gc(); for(; !std::isgraph(c); c = gc());for(; std::isgraph(c); c = gc()) *s++ = c; *s = 0; } inline void read(std::string& s) { s.clear(); char c = gc(); for(; !std::isgraph(c); c = gc()); for(; std::isgraph(c); c = gc()) s.push_back(c); } inline void pc(char c) { if(p3 - obuf == SIZE) fwrite(obuf, 1, SIZE, stdout), p3 = obuf; *p3++ = c; } inline void write(char c) { pc(c); } inline void write(const char* s) { while(*s) pc(*s), ++s; } inline void write(std::string s) { for(const char c : s) pc(c); } template<typename _Tp>inline void read(_Tp& x) { x = 0; char c = gc(); int f = 0; for(; !std::isdigit(c); c = gc()) f |= c == '-'; for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48); return f ? x = ~x + 1 : 1, void(); } template<typename _Tp>inline void write(_Tp x) { static int stk[40]; int tp = 0; if(!x) return pc('0'), void(); if(x < 0) pc('-'), x = ~x + 1; while(x) stk[++tp] = x % 10, x /= 10; while(tp) pc(stk[tp--] + '0'); } template<typename _Tp>inline void writesp(_Tp x) { write(x), pc(' '); } template<typename _Tp>inline void writeln(_Tp x) { write(x), pc('\n'); } template<typename _Tp, typename ...Args>inline void read(_Tp& x, Args& ...args) { read(x), read(args...); } template<typename _Tp, typename ...Args>inline void write(_Tp x, Args ...args) { write(x), write(args...); } template<typename _Tp, typename ...Args>inline void writesp(_Tp x, Args ...args) { writesp(x), writesp(args...); } template<typename _Tp, typename ...Args>inline void writeln(_Tp x, Args ...args) { writeln(x), writeln(args...); } inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); } }
using namespace FastIO;

constexpr int N = 1e6 + 10;
constexpr int RT = 1e3 + 10;

int n, q, block;
int tag[RT];
int a[N], d[N], bel[N];

inline void build(int n)
{
    block = (int)sqrt(n);
    rep (i, 1, n)
        bel[i] = (i - 1) / block + 1;
}

inline void add(int l, int r, int w)
{
    int L = bel[l];
    int R = bel[r];
    if (L == R)
    {
        rep (i, l, r)
            a[i] += w;
        return;
    }
    for (int i = l; bel[i] <= L; ++i)
        a[i] += w;
    rep(i, L + 1, R - 1)
        tag[i] += w;
    for (int i = r; bel[i] == R; --i)
        a[i] += w;
}

inline int query(int l, int r, int c)
{
    int res = 0, i = l;
    for (; i + 4 <= r; i += 4)
        res += (a[i] + tag[bel[i]]) >= c,
        res += (a[i + 1] + tag[bel[i + 1]]) >= c,
        res += (a[i + 2] + tag[bel[i + 2]]) >= c,
        res += (a[i + 3] + tag[bel[i + 3]]) >= c;
    for (; i <= r; ++i)
        res += (a[i] + tag[bel[i]]) >= c;
    return res;
}

int main()
{
    read(n, q);
    rep (i, 1, n) read(a[i]);

    int l, r, x;
    build(n);

    rep (i, 1, q)
    {
        char opr; read(opr);
        read(l, r, x);
        if (opr == 'M') add(l, r, x);
        else writeln(query(l, r, x));
    }

    return flush(), 0;
}