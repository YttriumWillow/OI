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

const int N = 3e5 + 10;
const int M = 3e5 + 10;

int n, m, q;
int dfncnt, dcccnt;
int dfn[N], low[N], dcc[N];
int sum[N], siz[N];
bool b[M << 1];
pair<int, int> qry[N];

struct Graph
{
	struct Edge { int v, w, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, int w)
	{ e[++tot] = { v, w, h[u] }; h[u] = tot; }
} G, T;

namespace DSU
{
int fa[N], usiz[N];
inline void init(int n) { for (int i = 1; i <= n + 5; ++i) fa[i] = i, usiz[i] = 1; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
} using namespace DSU;

namespace TarjanLCA
{
struct QryGraph
{
	struct QEdge { int v, nxt; };
	QEdge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
} Q;
bool vis[N]; int res[N << 1];
inline void tarjanLCA(int u)
{
	vis[u] = 1;
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (vis[v]) continue;
		tarjanLCA(v); fa[v] = u;
	}
	for (int i = Q.h[u]; i; i = Q.e[i].nxt)
	{
		int v = Q.e[i].v;
		if (vis[v]) res[i ^ 1] = res[i] = find(v);
	}
}
inline int LCA(int i) { return res[i << 1]; }
} using namespace TarjanLCA;

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = G.h[u]; i; i = G.e[i].nxt)
	{
		int v = G.e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v]) b[i] = b[i ^ 1] = 1;
		}
		else if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

inline void dfs(int u)
{
	dcc[u] = dcccnt;
	for (int i = G.h[u]; i; i = G.e[i].nxt)
	{
		int v = G.e[i].v;
		if (dcc[v] == dcc[u]) siz[dcccnt] += G.e[i].w;
		if (!b[i] && !dcc[v])
			dfs(v), siz[dcccnt] += G.e[i].w;
	}
}

inline void rebuild()
{
	for (int u = 1; u <= n; ++u)
		for (int i = G.h[u]; i; i = G.e[i].nxt)
		{
			int v = G.e[i].v;
			if (dcc[u] != dcc[v])
				T.add(dcc[u], dcc[v], G.e[i].w);
		}
	rep (i, 1, dcccnt) sum[i] = siz[i];
}

inline void fix(int u, int fa)
{
	sum[u] += sum[fa];
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (v == fa) continue;
		sum[v] += T.e[i].w; fix(v, u);
	}
}

int main()
{
	read(n, m);

	rep (i, 1, m)
	{
		int u, v, w; read(u, v, w);
		G.add(u, v, w); G.add(v, u, w);
	}

	rep (i, 1, n) if (!dfn[i]) tarjan(i, 0);
	rep (i, 1, n) if (!dcc[i]) ++dcccnt, dfs(i);

	rebuild(); fix(1, 0);

	read(q);

	rep (i, 1, q)
	{
		int u, v; read(u, v);
		qry[i] = { dcc[u], dcc[v] };
		Q.add(dcc[u], dcc[v]);
		Q.add(dcc[v], dcc[u]);
	}

	init(dcccnt); tarjanLCA(1);

	rep (i, 1, q)
	{
		int &u = qry[i].first, &v = qry[i].second;
		if (sum[u] + sum[v] - (sum[res[i << 1]] << 1) + siz[res[i << 1]] > 0)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}