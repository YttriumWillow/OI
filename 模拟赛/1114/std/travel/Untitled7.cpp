#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define long long long
struct modein{
	template<class T>
	modein operator >>(T &x){
		x=0;char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return (modein){};
	}
}qin;
struct edge{
	int next,to,v;
}e[100010];
int head[100010],in[100010],to[100010],cnt,n,m,T;
void add(int a,int b,int c){
	e[++cnt].to=b;
	e[cnt].next=head[a];
	e[cnt].v=c;
	head[a]=cnt;
}
int pt[100010],low[100010],dfn[100010],idx;
int pv[100010],dis[100010],hav[100010],tot,cs[100010];
int heap[100010],st[100010],top,now;long k,ans,ret;
int dp[1010][5010][2],sk[100010],tok;bool ban[100010],usd[100010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void app(int a,int b){
	if(!a||!b)return;
	e[++cnt].to=b;
	e[cnt].next=heap[a];
	heap[a]=cnt;
	e[++cnt].to=a;
	e[cnt].next=heap[b];
	heap[b]=cnt;
}
void make(int p,int f,int w){
	hav[++tot]=w;
	for(int i=p;i!=f;i=pt[i])in[i]=tot,hav[tot]+=pv[i],cs[tot]++;
	to[tot]=f;
}
void dfs(int p){
	dfn[p]=++idx;
	for(int i=head[p];i;i=e[i].next){
		if(!dfn[e[i].to]){
			dis[e[i].to]=dis[p]+e[i].v;
			pt[e[i].to]=p,pv[e[i].to]=e[i].v;
			dfs(e[i].to);
		}else make(p,e[i].to,e[i].v);
	}
}
void cfs(int p){
	usd[p]=true;
	for(int i=heap[p];i;i=e[i].next){
		if(!ban[e[i].to]&&!usd[e[i].to]){
			cfs(e[i].to);
			for(int j=0;j<now;j++)dp[p][j][1]=min(dp[p][j][1],dp[e[i].to][j][0]);
		}
	}
	dp[p][hav[p]%now][1]=min(dp[p][hav[p]%now][1],hav[p]),tok=0;
	for(int i=1;i<now;i++)if(dp[p][i][1]<1e9)sk[++tok]=dp[p][i][1];
	while(!q.empty())q.pop();dp[p][hav[p]%now][0]=hav[p],q.push({hav[p],hav[p]%now});
	for(pair<int,int>t;!q.empty();){
		t=q.top(),q.pop();
		if(t.first!=dp[p][t.second][0])continue;
		for(int i=1;i<=tok;i++){
			if(t.first+sk[i]<dp[p][(t.first+sk[i])%now][0]){
				dp[p][(t.first+sk[i])%now][0]=t.first+sk[i];
				q.push({dp[p][(t.first+sk[i])%now][0],(t.first+sk[i])%now});
			}
		}
	}
}
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	qin>>n>>m>>k>>T;
	for(int i=1,a,b,c;i<=m;i++)qin>>a>>b>>c,add(a,b,c);
	dfs(1);
	for(int i=1;i<=tot;i++)app(in[to[i]],i);
	for(int a;T--;){
		qin>>a,top=0,now=1e9,ret=k-dis[a];
		for(int i=1;i<=tot;i++)usd[i]=ban[i]=false;ban[in[a]]=true;
		for(int i=1;i<=tot;i++)if(to[i]==a)ban[i]=true;
		for(int i=a;i;i=pt[i]){
			if(in[i]&&!ban[in[i]]&&!usd[in[i]])st[++top]=in[i],usd[in[i]]=true;
			for(int j=1;j<=tot;j++)if(to[j]==i&&!ban[j]&&!usd[j])st[++top]=j,usd[j]=true;
		}
		for(int i=1;i<=top;i++)now=min(now,hav[st[i]]);
		if(now<1e9){
			for(int i=0;i<=tot;i++)for(int j=0;j<now;j++)dp[i][j][0]=dp[i][j][1]=1e9;
			for(int i=1;i<=top;i++)cfs(st[i]);tok=0;
			for(int i=1;i<=top;i++)for(int j=1;j<now;j++)dp[0][j][1]=min(dp[0][j][1],dp[st[i]][j][0]);
			for(int i=1;i<now;i++)if(dp[0][i][1]<1e9)sk[++tok]=dp[0][i][1];
			while(!q.empty())q.pop();dp[0][0][0]=0,q.push({0,0});
			for(pair<int,int>t;!q.empty();){
				t=q.top(),q.pop();
				if(t.first!=dp[0][t.second][0])continue;
				for(int i=1;i<=tok;i++){
					if(t.first+sk[i]<dp[0][(t.first+sk[i])%now][0]){
						dp[0][(t.first+sk[i])%now][0]=t.first+sk[i];
						q.push({dp[0][(t.first+sk[i])%now][0],(t.first+sk[i])%now});
					}
				}
			}
			for(int i=0;i<now;i++)if(dp[0][i][0]<=ret&&dp[0][i][0]!=1e9)ans+=(ret-dp[0][i][0])/now+1;
			cout<<ans<<endl,ans=0;
		}else cout<<(ret>=0)<<endl;
	}
	return 0;
}
