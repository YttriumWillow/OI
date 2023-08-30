#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO
{
static constexpr int SIZE = 1 << 21;
char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
inline void read(char &c)
{
    for (c = gc(); !std::isgraph(c); c = gc())
        ;
}
inline void read(char *s)
{
    char c = gc();
    for (; !std::isgraph(c); c = gc())
        ;
    for (; std::isgraph(c); c = gc())
        *s++ = c;
    *s = 0;
}
inline void read(std::string &s)
{
    s.clear();
    char c = gc();
    for (; !std::isgraph(c); c = gc())
        ;
    for (; std::isgraph(c); c = gc())
        s.push_back(c);
}
inline void pc(char c)
{
    if (p3 - obuf == SIZE)
        fwrite(obuf, 1, SIZE, stdout), p3 = obuf;
    *p3++ = c;
}
inline void write(char c)
{
    pc(c);
}
inline void write(const char *s)
{
    while (*s)
        pc(*s), ++s;
}
inline void write(std::string s)
{
    for (const char c : s)
        pc(c);
}
template <typename _Tp> inline void read(_Tp &x)
{
    x = 0;
    char c = gc();
    int f = 0;
    for (; !std::isdigit(c); c = gc())
        f |= c == '-';
    for (; std::isdigit(c); c = gc())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return f ? x = ~x + 1 : 1, void();
}
template <typename _Tp> inline void write(_Tp x)
{
    static int stk[40];
    int tp = 0;
    if (!x)
        return pc('0'), void();
    if (x < 0)
        pc('-'), x = ~x + 1;
    while (x)
        stk[++tp] = x % 10, x /= 10;
    while (tp)
        pc(stk[tp--] + '0');
}
template <typename _Tp> inline void writesp(_Tp x)
{
    write(x), pc(' ');
}
template <typename _Tp> inline void writeln(_Tp x)
{
    write(x), pc('\n');
}
template <typename _Tp, typename... Args> inline void read(_Tp &x, Args &...args)
{
    read(x), read(args...);
}
template <typename _Tp, typename... Args> inline void write(_Tp x, Args... args)
{
    write(x), write(args...);
}
template <typename _Tp, typename... Args> inline void writesp(_Tp x, Args... args)
{
    writesp(x), writesp(args...);
}
template <typename _Tp, typename... Args> inline void writeln(_Tp x, Args... args)
{
    writeln(x), writeln(args...);
}
inline void flush()
{
    fwrite(obuf, p3 - obuf, 1, stdout);
}
} // namespace FastIO
using namespace FastIO;

const int N = 1e5 + 10;

int n, buc[N];
int cnt, res;
string s;

signed main()
{
    int T;
    read(T);
    while (T--)
    {
        read(n, s);
        res = cnt = 0;
        buc[++cnt] = -1;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'B')
                buc[++cnt] = i;
        buc[++cnt] = n;
        for (int i = 1; i < cnt; ++i)
        {
            int j = i + 1, t = buc[j] - buc[i] - 1;
            if (t + 2 <= res)
                continue;
            if (i > 2)
            {
                int p = i;
                while (p > 2 && buc[p] - buc[p - 1] == 2)
                    --p;
                if (p > 2 && buc[p] - buc[p - 1] == 3)
                    ++t;
            }
            if (j + 1 < cnt)
            {
                int q = j;
                while (q < cnt - 1 && buc[q + 1] - buc[q] == 2)
                    ++q;
                if (q < cnt - 1 && buc[q + 1] - buc[q] == 3)
                    ++t;
            }
            res = max(res, t);
        }

        writeln(res);
    }
    flush();
    return 0;
}