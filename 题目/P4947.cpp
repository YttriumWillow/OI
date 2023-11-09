#include <iostream>
#include <cstring>
#include <map>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO { static constexpr int SIZE = 1 << 21; char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf; inline void read(char& c) { for(c = gc(); !std::isgraph(c); c = gc()); } inline void read(char* s) { char c = gc(); for(; !std::isgraph(c); c = gc());for(; std::isgraph(c); c = gc()) *s++ = c; *s = 0; } inline void read(std::string& s) { s.clear(); char c = gc(); for(; !std::isgraph(c); c = gc()); for(; std::isgraph(c); c = gc()) s.push_back(c); } inline void pc(char c) { if(p3 - obuf == SIZE) fwrite(obuf, 1, SIZE, stdout), p3 = obuf; *p3++ = c; } inline void write(char c) { pc(c); } inline void write(const char* s) { while(*s) pc(*s), ++s; } inline void write(std::string s) { for(const char c : s) pc(c); } template<typename _Tp>inline void read(_Tp& x) { x = 0; char c = gc(); int f = 0; for(; !std::isdigit(c); c = gc()) f |= c == '-'; for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48); return f ? x = ~x + 1 : 1, void(); } template<typename _Tp>inline void write(_Tp x) { static int stk[40]; int tp = 0; if(!x) return pc('0'), void(); if(x < 0) pc('-'), x = ~x + 1; while(x) stk[++tp] = x % 10, x /= 10; while(tp) pc(stk[tp--] + '0'); } template<typename _Tp>inline void writesp(_Tp x) { write(x), pc(' '); } template<typename _Tp>inline void writeln(_Tp x) { write(x), pc('\n'); } template<typename _Tp, typename ...Args>inline void read(_Tp& x, Args& ...args) { read(x), read(args...); } template<typename _Tp, typename ...Args>inline void write(_Tp x, Args ...args) { write(x), write(args...); } template<typename _Tp, typename ...Args>inline void writesp(_Tp x, Args ...args) { writesp(x), writesp(args...); } template<typename _Tp, typename ...Args>inline void writeln(_Tp x, Args ...args) { writeln(x), writeln(args...); } inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); } }
using namespace FastIO;

const int N = 4e5 + 10;
const int M = 4e5 + 10;


struct Graph
{
	struct Edge { int v, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
};

// Dynamic Point-Creating Segment Tree
struct SegTree
{
	int tot = 0;
	struct Node { int ls, rs, v; } t[N << 5];
	inline int newNode() { return ++tot; }
	inline void pushup(int p) { Node &T = t[p]; T.v = t[T.ls].v + t[T.rs].v; }
	inline void modify(int &p, int l, int r, int pos, int val)
	{
		if (!p) { p = newNode(); } Node &T = t[p]; T.v += val;
		if (l == r) { return; }
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(T.ls, l, mid, pos, val);
		if (mid  < pos) modify(T.rs, mid + 1, r, pos, val);
	}
	inline int clear(int &p, int l, int r, int ql, int qr)
	{
		if (!p) { return 0; } Node &T = t[p];
		if (ql <= l and r <= qr) { p = 0; return T.v; }
		int mid = (l + r) >> 1, res = 0;
		if (ql <= mid) res += clear(T.ls, l, mid, ql, qr);
		if (mid  < qr) res += clear(T.rs, mid + 1, r, ql, qr);
		pushup(p); if (!T.v) p = 0;
		return res;
	}
	inline int query(int &p, int l, int r, int ql, int qr)
	{
		if (!p) { return 0; } Node &T = t[p];
		if (ql <= l and r <= qr) { return T.v; }
		int mid = (l + r) >> 1, res = 0;
		if (ql <= mid) res += query(T.ls, l, mid, ql, qr);
		if (mid  < qr) res += query(T.rs, mid + 1, r, ql, qr);
		return res;
	}
};

int n, q;
Graph T;
SegTree SGT;
int root[N << 5];

namespace HLD
{
int cnt;
int fa[N], dep[N], dfn[N], rnk[N], siz[N], hsn[N], top[N];
inline void dfs1(int u)
{
	hsn[u] = -1; siz[u] = 1; dep[u] = dep[fa[u]] + 1;
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v; if (v == fa[u]) continue;
		if (!dep[v])
		{
			fa[v] = u; dfs1(v);
			siz[u] += siz[v];
			if (!~hsn[u] or siz[v] > siz[hsn[u]]) hsn[u] = v;
		}
	}
}
inline void dfs2(int u, int tp)
{
	top[u] = tp; dfn[u] = ++cnt; rnk[cnt] = dfn[u];
	if (!~hsn[u]) return;
	dfs2(hsn[u], tp);
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (v != hsn[u] and v != fa[u])
			dfs2(v, v);
	}
}
inline int LCA(int u, int v)
{
	while (top[u] ^ top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return u;
}
inline int queryEdge(int &p, int u, int v)
{
	int res = 0;
	while (top[u] ^ top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res += SGT.query(p, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	res += SGT.query(p, 1, n, dfn[u], dfn[v]);
	return res;
}
inline int clearEdge(int &p, int u, int v)
{
	int res = 0;
	while (top[u] ^ top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res += SGT.clear(p, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	res += SGT.clear(p, 1, n, dfn[u], dfn[v]);
	return res;
}
} using namespace HLD;

int main()
{
	read(n, q);
	rep (i, 2, n)
	{
		int u, v; read(u, v);
		T.add(u, v); T.add(v, u);
	}

	dfs1(1); dfs2(1, 1);

	map<string, int> mp;

	int cnttyp = 0;

	rep (i, 1, n)
	{
		int k; read(k);
		while (k--)
		{
			string s; read(s);
			if (!mp.count(s)) mp[s] = ++cnttyp;
			SGT.modify(root[mp[s]], 1, n, dfn[i], 1);
		}
	}

	// int tot = 0;
	while (q--)
	{
		string opr, opn, typ; int u, v, lca;
		read(opr, opn, u, v);
		if (opr == "query")
		{
			if (opn == "/p")
			{
				lca = LCA(u, v);
				writeln(dep[u] + dep[v] - 2 * dep[lca]);
			}
			else
			{
				read(typ);
				typ = typ.substr(2);
				if (!mp.count(typ)) writeln(0);
				else 				writeln(queryEdge(root[mp[typ]], u, v));
			}
		}
		else
		{
			read(typ);
			typ = typ.substr(2);
			if (!mp.count(typ)) writeln(0);
			else 				writeln(clearEdge(root[mp[typ]], u, v));
		}
	}

	return flush(), 0;
}