#include<iostream>
#include<cstdio>
using namespace std;
struct modein{
	modein operator >>(int &x){
		x=0;char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return (modein){};
	}
}qin;
struct modeout{
	void wrte(int x){
		if(x>9)wrte(x/10);
		putchar(x%10^48);
	}
	modeout operator <<(const int &x){
		wrte(x),putchar(' ');
		return (modeout){};
	}
}qout;
struct edge{
	int next,to;
}e[2000010];
int head[1000010],n,cnt,k;
int dp[1000010][2],goin[1000010];
void add(int a,int b){
	goin[b]++;
	e[++cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
bool dfs(int p,int f){
	for(int i=head[p];i;i=e[i].next){
		if(e[i].to!=f){
			if(dfs(e[i].to,p))dp[p][1]+=dp[e[i].to][0];
			else dp[p][0]+=dp[e[i].to][1];
		}
	}
	return !dp[p][1];
}
void cfs(int p,int f){
	if(dp[f][1]==((dp[p][1])?0:dp[p][0]))dp[p][1]+=dp[f][0]-dp[p][1];
	else dp[p][0]+=dp[f][1]-((dp[p][1])?0:dp[p][0]);
	for(int i=head[p];i;i=e[i].next)
		if(e[i].to!=f)cfs(e[i].to,p);
}
int main(){
	freopen("treegame.in","r",stdin);
	freopen("treegame.out","w",stdout);
	qin>>n>>k;
	if(n==1){
		printf("NO!");
		return 0;
	}
	for(int i=1,a,b;i<n;i++)qin>>a>>b,add(a,b),add(b,a);
	for(int i=1;i<=n;i++)if(goin[i]==1)dp[i][0]=1;
	dfs(1,1);for(int i=head[1];i;i=e[i].next)cfs(e[i].to,1);
	if(k==1){for(int i=1;i<=n;i++)if(dp[i][1])qout<<i;
	}else for(int i=1;i<=n;i++)if(dp[i][1])qout<<dp[i][1];
	return 0;
}
