#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Query pair<int, int>
#define lowbit(x) (x & -x)

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

const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int Q = 5e5 + 10;

struct Edge { int v; i64 w; int nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, i64& w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

int n, m, q;	
int u, v; i64 V, w;
int col[N]; bool res[Q];

Query qry[Q];

inline void bfs(int s, i64& pre)
{
	queue<int> q;
	q.push(s); col[s] = s;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v; i64 w = e[i].w;
			if (!col[v] && (pre & w) == pre)
				q.push(v), col[v] = s;
		}
	}
}

inline void bitchecker(i64 pre)
{
	fill(col + 1, col + n + 5, 0);
	for (int i = 1; i <= n; ++i)
		if (!col[i]) bfs(i, pre);
	for (int i = 1; i <= q; ++i)
		res[i] = res[i] || (col[qry[i].first] == col[qry[i].second]);
}

signed main()
{
	read(n, m, q, V);

	for (int i = 1; i <= m; ++i)
	{
		read(u, v, w);
		add(u, v, w);
		add(v, u, w);
	}

	for (int i = 1; i <= q; ++i)
		read(qry[i].first, qry[i].second);

	if (V != 0ll) //            (1 << 60ll)
		for (i64 pre = V; pre < (1ll << 60); pre += lowbit(pre))
			bitchecker(pre);
	else
		bitchecker(0);

	for (int i = 1; i <= q; ++i)
		puts(res[i] ? "Yes" : "No");

	return 0;
}