#include <cstdio>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin)),p1==p2?EOF:*p1++)
using namespace std;
char buf[1<<22],*p1=buf,*p2=buf;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int N=3000003,M=1000003,P=1000000007;
int n,m,res;
int a[N];
int pos[3],rk;
int b[N],len;
int f[N],cnt[N];
int las[M];
void solve(){
	for(int i=1;i<=n;++i) las[i]=0;
	f[0]=0;cnt[0]=1;
	for(int i=1;i<=len;++i){
		f[i]=f[i-1];
		cnt[i]=cnt[i-1];
		if(las[b[i]]){
			int p=las[b[i]]-1;
			if(f[i]<f[p]+1) f[i]=f[p]+1,cnt[i]=0;
			if(f[i]==f[p]+1){
				cnt[i]+=cnt[p];
				if(cnt[i]>=P) cnt[i]-=P;
			}
		}
		las[b[i]]=i;
	}
	if(f[len]==n-1){
		res+=cnt[len];
		if(res>=P) res-=P;
	}
}
int main(){
	n=read();m=n*3;
	for(int i=1;i<=m;++i){
		a[i]=read();
		if(a[i]==1) pos[rk++]=i;
	}
	len=0;
	for(int i=pos[0]+1;i<pos[2];++i) b[++len]=a[i];
	solve();
	len=0;
	for(int i=pos[1]+1;i<=m;++i) b[++len]=a[i];
	for(int i=1;i<pos[0];++i) b[++len]=a[i];
	solve();
	len=0;
	for(int i=pos[2]+1;i<=m;++i) b[++len]=a[i];
	for(int i=1;i<pos[1];++i) b[++len]=a[i];
	solve();
	printf("%d\n",res);
	return 0;
}
