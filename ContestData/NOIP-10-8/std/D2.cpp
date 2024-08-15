#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
#define N 500005
#define fi first
#define se second
#define pli pair<ll,int>
const int p=1e9+7;
int n,m,i,v,x,y[N<<2],id[N],c,nxt[N<<2];
ll z[N<<2],w,ans;
bool vis[N<<2];
vector<pair<int,int> > G[N];
priority_queue<pli > s;
pli u;
int f[N],sz[N];
int ge(int x){
	return f[x]==x?x:f[x]=ge(f[x]);
}
bool cmp(int x,int y){
	return z[x]>z[y];
}
int main()
{
	scan(n),scan(m);
	for(i=2;i<=m*2;i+=2){
		scan(x),scan(y[i]),scan(z[i]);
		if(x>y[i]) swap(x,y[i]);
		if(y[i]==x+1) s.push(make_pair(-z[i],i)),vis[i]=1;
		if(x==1&&y[i]==n) s.push(make_pair(-z[i],i+1)),vis[i+1]=1;
		y[i+1]=x,z[i+1]=z[i];
		G[x].emplace_back(make_pair(y[i],i)),G[y[i]].emplace_back(make_pair(x,i+1));
	}
	if(n==2) return putint(z[2],'\n'),flush(),0;
	for(i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
		reverse(G[i].begin(),G[i].end());
		for(int j=1;j<G[i].size();j++)
		nxt[G[i][j].se^1]=G[i][j-1].se;
		nxt[G[i][0].se^1]=G[i].back().se;
	}
	for(i=1;i<=m-n+1;i++){
		while(!vis[s.top().se]) s.pop();
		u=s.top(),s.pop(),vis[u.se]=0;
		w=-u.fi,x=nxt[u.se^1];
		while(x^u.se^1){
			z[x]+=w,z[x^1]+=w;
			if(vis[x^1]) id[++c]=x^1,vis[x^1]=0;
			else vis[x]=1,s.push(make_pair(-z[x],x));
			x=nxt[x];
		}
	}
	sort(id+1,id+c+1,cmp);
	for(i=1;i<=n;i++) f[i]=i,sz[i]=1;
	for(i=1;i<=c;i++){
		int u=ge(y[id[i]]),v=ge(y[id[i]^1]);
		if(sz[u]<sz[v]) swap(u,v);
		ans=(ans+z[id[i]]%p*sz[u]%p*sz[v])%p;
		f[v]=u,sz[u]+=sz[v];
	}
	putint(ans,'\n');flush();
	return 0;
}
