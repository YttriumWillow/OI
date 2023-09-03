#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct Edge { int v, nxt; };
Edge eo[M << 1]; int ho[N], toto;
Edge e1[M << 1]; int h1[N], tot1;
Edge e2[M << 1]; int h2[N], tot2;
inline void add(int u, int v)
{ eo[++toto] = { v, ho[u] }, toto = ho[u]; }
inline void add1(int u, int v)
{ e1[++tot1] = { v, h1[u] }, tot1 = h1[u]; }
inline void add2(int u, int v)
{ e2[++tot2] = { v, h2[u] }, tot2 = h2[u]; }
int n, m, ans, S;
int dfncnt, scccnt;
int dfn[N], low[N];
int scc[N], w[N];
int d1[N], d2[N];
bool ins[N], vis[N];
stack<int> st;

inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	st.push(u); ins[u] = 1;
	for (int i = ho[u]; i; i = eo[i].nxt)
	{
		int v = eo[i].v;
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++scccnt;
		do {
			scc[u] = scccnt;
			++w[scccnt];
			ins[u] = 0;
			u = st.top(); st.pop(); 
		} while (dfn[u] != low[u]);
	}
}

inline void SPFA1(int s)
{
	queue<int> q; q.push(s);
	vis[s] = 1; d1[s] = w[s];
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h1[u]; i; i = e1[i].nxt)
		{
			int v = e1[i].v;
            if (d1[v] < d1[u] + w[v])
            {
                d1[v] = d1[u] + w[v];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

inline void SPFA2(int s)
{
	queue<int> q; q.push(s);
	vis[s] = 1; d2[s] = w[s];
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h2[u]; i; i = e2[i].nxt)
		{
			int v = e2[i].v;
            if (d2[v] < d2[u] + w[v])
            {
                d2[v] = d2[u] + w[v];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
		
	cerr << "tarjan suc!" << endl;
    for (int i = 1; i <= n; ++i)
    	cerr << scc[i] << " \n"[i == n];
	
	for (int u = 1; u <= n; ++u)
		for (int i = ho[u]; i; i = eo[i].nxt)
		{
			int v = eo[i].v;
			if (scc[u] != scc[v])
			{
				add1(scc[u], scc[v]);
				add2(scc[v], scc[u]);
			}
		}
	
    for (int u = 1; u <= scccnt; ++u)
    {
    	cerr << u << " : ";
    	for (int i = h1[u]; i; i = e1[i].nxt)
    		cerr << e1[i].v << ' ';
    	cerr << endl;
    }
    for (int u = 1; u <= scccnt; ++u)
    {
    	cerr << u << " : ";
    	for (int i = h2[u]; i; i = e2[i].nxt)
    		cerr << e2[i].v << ' ';
    	cerr << endl;
    }
	
	S = scc[1]; ans = w[S];
	SPFA1(S), SPFA2(S);
	
	cerr << "SPFA suc!" << endl;
    for (int i = 1; i <= scccnt; ++i)
    	cerr << d1[i] << " \n"[i == scccnt];
    for (int i = 1; i <= scccnt; ++i)
    	cerr << d2[i] << " \n"[i == scccnt];
	
	for (int x = 1; x <= n; ++x)
    if (!vis[scc[x]] && d1[scc[x]])
    {
        int u = scc[x]; vis[u] = 1;
        for (int i = h2[u]; i; i = e2[i].nxt)
        {
             int v = e2[i].v;
             if (!d2[v]) continue;
             ans = max(ans, d1[u] + d2[v] - w[S]);
        }
    }
	cout << ans << endl;
	return 0;
}

