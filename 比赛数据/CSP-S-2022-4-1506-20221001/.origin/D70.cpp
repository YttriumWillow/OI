#include<bits/stdc++.h>
#define ll long long
#define mxn 100003
#define md 1000000007
#define pb push_back
#define mkp make_pair
#define ld long double
#define umap unordered_map
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define pq priority_queue
using namespace std;
struct node{
	int l,r,x;
}t[mxn<<5];
int n,T,m,ans,cnt,tot,d[mxn],L[mxn],R[mxn],rt[mxn],dfn[mxn],up[mxn][20],fa[mxn][20];
vector<int>g[mxn],q[mxn];
int add(int k,int x,int l,int r){
	int p=++cnt;t[p]=t[k],t[p].x++;
	if(l==r)return p;
	int mid=(l+r)>>1;
	if(x<=mid)t[p].l=add(t[k].l,x,l,mid);
	else t[p].r=add(t[k].r,x,mid+1,r);
	return p;
}
int ask(int lp,int rp,int l,int r,int L,int R){
	if(l<=L&&R<=r)return t[rp].x-t[lp].x;
	int mid=(L+R)>>1;
	if(l<=mid&&r>mid)return ask(t[lp].l,t[rp].l,l,r,L,mid)+ask(t[lp].r,t[rp].r,l,r,mid+1,R);
	if(l<=mid)return ask(t[lp].l,t[rp].l,l,r,L,mid);
	return ask(t[lp].r,t[rp].r,l,r,mid+1,R);
}
void dfs(int x,int f){
	d[x]=d[f]+1;
	fa[x][0]=f;
	L[x]=dfn[x]=++tot;
	rept(i,1,18)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i:g[x])if(i!=f)dfs(i,x);
	R[x]=tot;
}
int lca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	drep(i,17,0)if(d[fa[y][i]]>=d[x])y=fa[y][i];
	if(x==y)return x;
	drep(i,17,0)if(fa[y][i]!=fa[x][i])
		y=fa[y][i],x=fa[x][i];
	return fa[x][0];
}
int maxn(int x,int y){
	return d[x]>d[y]?y:x;
}
void dfs1(int x,int fa){
	for(int i:g[x])if(i!=fa){
		dfs1(i,x);
		up[x][0]=maxn(up[x][0],up[i][0]);
	}
	//cout<<x<<":"<<up[x][0]<<endl;
}
void dfs2(int x,int fa){
	rept(i,1,18)up[x][i]=up[up[x][i-1]][i-1];
	//cout<<x<<"::"<<up[x][1]<<endl;
	for(int i:g[x])if(i!=fa){
		dfs2(i,x);
	}
}
signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&T,&m);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		g[x].pb(y),g[y].pb(x);
	}
	dfs(1,0);
	rep(i,1,n)up[i][0]=i;
	for(int i=0,x,y,lc;i<T;++i){
		scanf("%d%d",&x,&y);
		if(dfn[x]>dfn[y])swap(x,y);
		q[dfn[x]].pb(dfn[y]);
		lc=lca(x,y);
		up[x][0]=maxn(up[x][0],lc);
		up[y][0]=maxn(up[y][0],lc);
	}
	rep(i,1,n){
		rt[i]=rt[i-1];
		for(int j:q[i])rt[i]=add(rt[i],j,1,n);
	}
	dfs1(1,0);
	dfs2(1,0);
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		if(dfn[x]>dfn[y])swap(x,y);
		int lc=lca(x,y);
		if(d[up[x][17]]>d[lc]||d[up[y][17]]>d[lc]){
			puts("-1");
			continue;
		}
		ans=0;
		drep(i,17,0)if((!i||up[x][i]!=up[x][i-1])&&d[up[x][i]]>d[lc])ans+=1<<i,x=up[x][i];
		drep(i,17,0)if((!i||up[x][i]!=up[x][i-1])&&d[up[y][i]]>d[lc])ans+=1<<i,y=up[y][i];
		//cout<<x<<" "<<y<<":"<<ans<<endl;
		if(x==lc||y==lc){
			printf("%d\n",ans);
			continue;
		}
		printf("%d\n",ans+(!ask(rt[L[x]-1],rt[R[x]],L[y],R[y],1,n)));
	}
	return 0;
}
