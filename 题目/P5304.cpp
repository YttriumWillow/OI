// Problem:       P5304 [GXOI/GZOI2019] 旅行者
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P5304
// Memory Limit:  500 MB
// Time Limit:    5000 ms
// Created Time:  2023-08-04 11:12:06 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define Pli pair<i64, int>

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
const i64 inf = 0x3f3f3f3f3f3f3f3f;
	
int n, m, k;
int S, T, p[N];
bool vis[N];
i64 ans, d[N];

struct Edge { int v, w, nxt; };

Edge e[M << 1]; int tot, h[N];
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }
inline void clear()
{ tot = 0; fill(h + 1, h + n + 3, 0); }

struct Save { int u, v, w; } pre[M];
inline void prefix()
{
	for (int i = 1; i <= m; ++i)
		add(pre[i].u, pre[i].v, pre[i].w);
}

inline i64 dijkstra(int s, int t)
{
	priority_queue<Pli, vector<Pli>, greater<Pli>> q;
	fill(d + 1, d + n + 3, inf);
	fill(vis + 1, vis + n + 3, 0);
	d[s] = 0; q.push({ 0, s });
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
				q.push({ d[v] = d[u] + e[i].w, v });
		}
	}
	return d[t];
}

inline void solve()
{
	ans = inf;
	
	read(n, m, k);
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		read(u, v, w);
		pre[i] = { u, v, w };
	}
	for (int i = 1; i <= k; ++i)
		read(p[i]);
	
	S = n + 1, T = n + 2;
	for (int j = 0; (1 << j) <= k; ++j)
	{
		prefix();
		for (int i = 1; i <= k; ++i)
			i & (1 << j) ? add(S, p[i], 0) : add(p[i], T, 0);
		ans = min(ans, dijkstra(S, T));
		clear();
		
		prefix();
		for (int i = 1; i <= k; ++i)
			i & (1 << j) ? add(p[i], T, 0) : add(S, p[i], 0);
		ans = min(ans, dijkstra(S, T));
		clear();
	}
	
	writeln(ans);
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	
	int T; read(T);
	while (T--) solve();
	flushout();
	return 0;
}