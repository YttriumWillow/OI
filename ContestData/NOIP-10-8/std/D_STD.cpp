#include <cstdio>
#include <queue>
#include <vector>
#include <ctime>
#include <algorithm>
#define x first
#define y second
#define pb push_back
#define ll long long
using std::pair;
using std::vector;
using std::priority_queue;
const int N=3000005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

int n, m, cnt[N], id[N], sz[N];
int u[N], v[N], tp=1;
ll c[N];
int x[N], y[N], top, fa[N];
ll w[N];
inline void add(int a, int b, ll c)
{
	// printf("add %d %d %d\n", a, b, c);
	x[++top]=a, y[top]=b, w[top]=c, id[top]=top;
}
int ct[N], to[N];
vector<int> e[N];
// int nxt[N], pr[N];
priority_queue<pair<ll, int> > q;
inline int findfa(int x) { return fa[x]==x?x:fa[x]=findfa(fa[x]); }
int main()
{
	freopen("pairs_hack1.in", "r", stdin);
	freopen("pairs_hack1.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1, x, y, z; i<=m; ++i)
	{
		scan(x), scan(y), scan(z);
		u[++tp]=x, v[tp]=y, c[tp]=z;
		e[x].pb(tp);
		u[++tp]=y, v[tp]=x, c[tp]=z;
		e[y].pb(tp);
	}
	for(int i=1; i<=n; ++i)
	{
		sz[i]=1;
		fa[i]=i;
		std::sort(e[i].begin(), e[i].end(), [&] (int a, int b) { return (v[a]+n-i-1)%n+1<(v[b]+n-i-1)%n+1; } );
		for(int t=0; t+1<e[i].size(); ++t) to[e[i][t]^1]=e[i][t+1];
		int v=e[i].back();
		q.push({-c[v], v});
		ct[v]=ct[v^1]=1;
	}
	while(!q.empty())
	{
		auto t=q.top();
		auto d=t.first;
		auto u=t.second;
		// auto [d, u]=q.top();
		d=-d;
		q.pop();
		if(ct[u]>1) continue;
		int x=u;
		do{
			if(ct[x])
			{
				if(x!=u) add(::u[x], v[x], c[x]+d);
				ct[x]=ct[x^1]=2;
			}
			else
			{
				ct[x]=ct[x^1]=1;
				c[x]+=d, c[x^1]+=d;
				q.push({-c[x], x^1});
			}
			x=to[x];
		}while(x!=u);
	}
	std::sort(id+1, id+top+1, [] (int a, int b) { return w[a]>w[b]; } );
	int ans=0;
	for(int i=1; i<=top; ++i)
	{
		int u=id[i];
		int x=findfa(::x[u]), y=findfa(::y[u]);
		if(x!=y)
		{
			inc(ans, 1ll*sz[x]*sz[y]%MOD*(w[u]%MOD)%MOD);
			fa[x]=y;
			sz[y]+=sz[x];
		}
	}
	printf("%d\n", ans);
	fprintf(stderr, "time: %d\n", clock());
	return 0;
}
