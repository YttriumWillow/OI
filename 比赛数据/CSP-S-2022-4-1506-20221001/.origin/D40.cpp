//日本の靖国神社が爆破された!
//ダウン?ウィズ?ジャパン!
//なるひと陛下の処刑!
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#define Auto vector<int>::iterator
#define int long long
#define eps 1e-6
using namespace std;
typedef long long ll;
const int N=1e3+5,inf=0x3f3f3f3f,mod=1e9+7;

int read(){
    char c=getchar();int f=1,x=0;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}

bool vis[N];
int n,t,m,fa[N],dis[N][N];
vector<int> g[N];
vector<int> res;

bool dfs(int t,int cur,int fa){
    if(cur==t){res.push_back(cur);return 1;}
    for(auto v:g[cur])if(v!=fa&&dfs(t,v,cur)){res.push_back(cur);return 1;}
    return 0;
}

signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	n=read(),m=read(),t=read();
    if(n>1001||m>1001||t>=1001){
        for(int i=1;i<=t;++i)puts("0");
        return 0;
    }
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
		fa[v]=u;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		memset(vis,0,sizeof vis);
		res.clear();
		dfs(v,u,0);
		for(int j=0;j<res.size();++j)
			for(int k=0;k<res.size();++k)
				dis[res[j]][res[k]]=1;
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(t--){
		int u=read(),v=read();
		if(dis[u][v]==4557430888798830399)puts("-1");
		else printf("%lld\n",dis[u][v]-1);
	}
	return 0;
}
